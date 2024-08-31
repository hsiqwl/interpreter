#include "type_resolver.h"
#include "node_traits.h"

TypeResolver::TypeResolver(SymbolTableManager *manager): SharableObjectHolder<SymbolTableManager>(manager) {}

void TypeResolver::Visit(const VarDeclNode &node) {
    Return(node.GetType());
}

void TypeResolver::Visit(const SignedLiteralNode &node) {
    Return(TypeHolderWrapper{TypeHolder{TypeToken::Signed}});
}

void TypeResolver::Visit(const UnsignedLiteralNode &node) {
    Return(TypeHolderWrapper{TypeHolder{TypeToken::Unsigned}});
}

void TypeResolver::Visit(const CellLiteralNode &node) {
    Return(TypeHolderWrapper{TypeHolder{TypeToken::Cell}});
}

void TypeResolver::Visit(const VarReferenceNode &node) {
    if (object_ptr_->VarDeclaredInSomeScope(node.GetVarName()))
        Return(object_ptr_->GetVar(node.GetVarName()).GetType());
    else
        Return(std::make_shared<UseOfUndeclaredIdentifier>(node.GetLocation(), node.GetVarName()));
}

void TypeResolver::Visit(const AssignNode &node) {
    Return(GetValue(node.GetLeft(), object_ptr_));
}

void TypeResolver::Visit(const InitializationNode &node) {
    auto type = node.GetVarToInit().GetType();
    Return(std::move(type));
}

void TypeResolver::Visit(const BinaryOpNode &node) {
    auto left_type = GetValue(node.GetLeft(), object_ptr_);
    if (left_type.index() == 1) {
        Return(std::move(left_type));
        return;
    }
    auto right_type = GetValue(node.GetRight(), object_ptr_);
    if (right_type.index() == 1) {
        Return(std::move(right_type));
        return;
    }
    if (!std::get<0>(right_type).IsConvertibleTo(std::get<0>(left_type))) {
        Return(std::make_shared<NoKnownConversion>(node.GetLocation(), std::get<0>(right_type), std::get<0>(left_type)));
        return;
    }
    Return(std::move(left_type));
}

void TypeResolver::Visit(const StatementListNode &node) {
    Return(GetValue(node[node.NumOfStatements() - 1], object_ptr_));
}

void TypeResolver::Visit(const UnaryOpNode &node) {
    Return(GetValue(node.GetOperand(), object_ptr_));
}

void TypeResolver::Visit(const IfNode &node) {
    Return({});
}

void TypeResolver::Visit(const WhileNode &node) {
    Return({});
}

void TypeResolver::Visit(const FuncCallNode &node) {
    try {
        Return(object_ptr_->GetFunc(node.GetFuncName()).GetReturnType());
    } catch (std::out_of_range &error) {
        Return(std::make_shared<InfiniteRecursiveCall>(node.GetLocation(), node.GetFuncName()));
    }
}

void TypeResolver::Visit(const FuncDeclNode &node) {
    Return(TypeHolderWrapper{});
}

void TypeResolver::Visit(const XrayNode &node) {
    TypeHolder type{TypeToken::Cell};
    type.MakeMatrixWrap();
    Return(TypeHolderWrapper{type});
}

void TypeResolver::Visit(const RobotMoveNode &node) {
    Return({});
}

void TypeResolver::Visit(const MatrixElementReferenceNode &node) {
    if (object_ptr_->VarDeclaredInSomeScope(node.GetVarName()))
        Return(object_ptr_->GetVar(node.GetVarName()).GetType().GetInnerType());
    else
        Return(std::make_shared<UseOfUndeclaredIdentifier>(node.GetLocation(), node.GetVarName()));
}

void TypeResolver::Visit(const PrintNode &node) {
    Return(GetValue(node.GetExprToPrint(), object_ptr_));
}