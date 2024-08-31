#include "executor.h"
#include "node_traits.h"

Executor::Executor(ExecutionContext* context): SharableObjectHolder<ExecutionContext>(context) {}

std::vector<Value> Executor::PrepareArguments(const FuncCallNode &node) {
    std::vector<Value> args;
    for (const auto &iter: node.GetArgs()) {
        args.emplace_back(GetValue(*iter, object_ptr_).value());
    }
    return args;
}

void Executor::PassArguments(const FuncDeclNode &node, std::vector<Value> &&args) {
    auto arg_iter = args.begin();
    auto &call_stack = object_ptr_->GetCallStack();
    for (auto iter = node.GetFuncParams().begin(), end = node.GetFuncParams().end(); iter != end; ++iter, ++arg_iter) {
        call_stack.PutValue((*iter)->GetName(), std::move(*arg_iter));
    }
}

bool Executor::PredicateEvaluatesToTrue(Value &predicate_value) {
    bool evaluates_to_true = false;
    switch (predicate_value->GetType().GetSimpleType()) {
        case TypeToken::Signed: {
            evaluates_to_true = std::any_cast<int>(predicate_value->GetValue()) == 1;
            break;
        }
        case TypeToken::Unsigned: {
            evaluates_to_true = std::any_cast<unsigned>(predicate_value->GetValue()) == 1;
            break;
        }
        case TypeToken::Cell: {
            evaluates_to_true = static_cast<int>(std::any_cast<Cell>(predicate_value->GetValue())) == 1;
            break;
        }
    }
    return evaluates_to_true;
}

Value Executor::GetDefaultValue(const VarDeclNode &node) {
    if (node.GetType().IsSimpleType())
        return GetDefaultValueAccordingToType(node.GetType());
    Value contained_value = GetDefaultValueAccordingToType(node.GetType().GetInnerType());
    Value horizontal_index = GetValue(node.GetHorizontalSize(), object_ptr_).value();
    Value vertical_index = GetValue(node.GetVerticalSize(), object_ptr_).value();
    return MatrixValue(horizontal_index, vertical_index, contained_value, node.GetType());
}

Value Executor::GetDefaultValueAccordingToType(const TypeHolderWrapper &type) {
    if (type.IsSimpleType()) {
        switch (type.GetSimpleType()) {
            case TypeToken::Signed:
                return SignedValue();
            case TypeToken::Unsigned:
                return UnsignedValue();
            case TypeToken::Cell:
                return CellValue();
        }
    } else {
        Value contained_value = GetDefaultValueAccordingToType(type.GetInnerType());
        return MatrixValue(contained_value, type);
    }
}

void Executor::Visit(const SignedLiteralNode &node) {
    Return(node.GetValue());
}

void Executor::Visit(const UnsignedLiteralNode &node) {
    Return(node.GetValue());
}

void Executor::Visit(const CellLiteralNode &node) {
    Return(node.GetValue());
}

void Executor::Visit(const VarReferenceNode &node) {
    auto &call_stack = object_ptr_->GetCallStack();
    Return(call_stack.GetValue(node.GetVarName()));
}

void Executor::Visit(const VarDeclNode &node) {
    auto& call_stack = object_ptr_->GetCallStack();
    call_stack.RegisterValue(node.GetName(), GetDefaultValue(node));
    Return({std::nullopt});
}

void Executor::Visit(const InitializationNode &node) {
    node.GetVarToInit().Accept(*this);
    auto &call_stack = object_ptr_->GetCallStack();
    if (!node.InitExprIsEmpty()) {
        call_stack.PutValue(node.GetVarToInit().GetName(), GetValue(node.GetInitExpr(), object_ptr_).value());
    }
    Return(call_stack.GetValue(node.GetVarToInit().GetName()));
}

void Executor::Visit(const IfNode &node) {
    auto predicate_value = GetValue(node.GetPredicate(), object_ptr_).value();
    if (PredicateEvaluatesToTrue(predicate_value)) {
        auto &call_stack = object_ptr_->GetCallStack();
        call_stack.CreateNewFrame(call_stack.GetCurrentFrameName() + ": 'testonce'");
        GetValue(node.GetBody(), object_ptr_);
        call_stack.RemoveCurrentFrame();
    }
    Return({std::nullopt});
}

void Executor::Visit(const WhileNode &node) {
    auto predicate_value = GetValue(node.GetPredicate(), object_ptr_).value();
    while (PredicateEvaluatesToTrue(predicate_value)) {
        auto &call_stack = object_ptr_->GetCallStack();
        call_stack.CreateNewFrame(call_stack.GetCurrentFrameName() + ": 'testrep'");
        GetValue(node.GetBody(), object_ptr_);
        call_stack.RemoveCurrentFrame();
        predicate_value = GetValue(node.GetPredicate(), object_ptr_).value();
    }
    Return({std::nullopt});
}

void Executor::Visit(const AssignNode &node) {
    auto &call_stack = object_ptr_->GetCallStack();
    auto var_name = node.GetLeft().GetVarName();
    auto p_matrix_ref = dynamic_cast<const MatrixElementReferenceNode *>(&node.GetLeft());
    if (p_matrix_ref == nullptr) {
        call_stack.PutValue(var_name, GetValue(node.GetRight(), object_ptr_).value());
        Return(call_stack.GetValue(var_name));
    } else {
        auto &matrix = call_stack.GetValue(var_name);
        auto line = GetValue(p_matrix_ref->GetHorizontalIndex(), object_ptr_).value();
        auto column = GetValue(p_matrix_ref->GetVerticalIndex(), object_ptr_).value();
        auto &element = matrix->SubscriptOperator(*column, *line);
        element->SetValue(GetValue(node.GetRight(), object_ptr_).value());
        Return(element);
    }
}

void Executor::Visit(const UnaryOpNode &node) {
    auto operand_value = GetValue(node.GetOperand(), object_ptr_).value();
    switch (node.GetOpKind()) {
        case UnaryOpKind::Hash: {
            Return(operand_value->Hash());
            return;
        }
        case UnaryOpKind::Minus: {
            Return(operand_value->UnaryMinus());
            return;
        }
        case UnaryOpKind::Plus: {
            Return(operand_value->UnaryPlus());
            return;
        }
    }
}

void Executor::Visit(const BinaryOpNode &node) {
    auto lhs_value = GetValue(node.GetLeft(), object_ptr_).value();
    auto rhs_value = GetValue(node.GetRight(), object_ptr_).value();
    switch (node.GetOpKind()) {
        case BinaryOpKind::Plus: {
            Return(lhs_value->Plus(*rhs_value));
            return;
        }
        case BinaryOpKind::Minus: {
            Return(lhs_value->Minus(*rhs_value));
            return;
        }
        case BinaryOpKind::Star: {
            Return(lhs_value->Star(*rhs_value));
            return;
        }
        case BinaryOpKind::Slash: {
            Return(lhs_value->Slash(*rhs_value));
            return;
        }
        case BinaryOpKind::Less: {
            Return(lhs_value->Less(*rhs_value));
            return;
        }
        case BinaryOpKind::Greater: {
            Return(lhs_value->Greater(*rhs_value));
            return;
        }
        case BinaryOpKind::Equal: {
            Return(lhs_value->Equal(*rhs_value));
            return;
        }
        case BinaryOpKind::Percent: {
            Return(lhs_value->Percent(*rhs_value));
            return;
        }
    }
}

void Executor::Visit(const FuncDeclNode &node) {
    for (auto &param: node.GetFuncParams()) {
        param->Accept(*this);
    }
    Return({std::nullopt});
}

void Executor::Visit(const FuncCallNode &node) {
    auto &call_stack = object_ptr_->GetCallStack();
    auto args = PrepareArguments(node);
    call_stack.CreateNewFrame(node.GetFuncName());
    auto &executed_func = object_ptr_->GetFunc(node.GetFuncName());
    executed_func.Accept(*this);
    PassArguments(executed_func, std::move(args));
    Return(GetValue(executed_func.GetFuncBody(), object_ptr_));
    call_stack.RemoveCurrentFrame();
}

void Executor::Visit(const StatementListNode &node) {
    for (size_t i = 0; i < node.NumOfStatements() - 1; ++i) {
        node[i].Accept(*this);
    }
    Return(GetValue(node[node.NumOfStatements() - 1], object_ptr_));
}

void Executor::Visit(const XrayNode &node) {
    Value returned_value{std::any_cast<MatrixValue>(RemoteEnvironmentHandler::HandleXrayRequest())};
    Return(std::move(returned_value));
}

void Executor::Visit(const RobotMoveNode &node) {
    RemoteEnvironmentHandler::HandleMovementRequest(node.GetMoveDirection());
    Return({std::nullopt});
}

void Executor::Visit(const MatrixElementReferenceNode &node) {
    auto &call_stack = object_ptr_->GetCallStack();
    Value line = GetValue(node.GetHorizontalIndex(), object_ptr_).value();
    Value column = GetValue(node.GetVerticalIndex(), object_ptr_).value();
    Return(call_stack.GetValue(node.GetVarName())->SubscriptOperator(*column, *line));
}

void Executor::Visit(const PrintNode &node) {
    auto &env_stream = SingletonHolder<ExecutableEnvironmentOutputStream, Loader>::Instance();
    env_stream.Eat(GetValue(node.GetExprToPrint(), object_ptr_).value());
}