#include "semantic_analyzer.h"
#include "node_traits.h"

SemanticAnalyzer::SemanticAnalyzer(SymbolTableManager *manager): SharableObjectHolder<SymbolTableManager>(manager) {}

VarSymbol SemanticAnalyzer::CreateVarSymbol(const VarDeclNode &node) {
    return {node.GetName(), node.GetType(), node.IsConst()};
}

std::vector<std::shared_ptr<VarDeclNode>>
SemanticAnalyzer::MakeDeclarations(const FuncDeclNode &node, SemanticErrorContext& context) {
    std::vector<std::shared_ptr<VarDeclNode>> declarations;
    auto stmt_list_size = node.GetFuncBody().NumOfStatements();
    auto &func_body = node.GetFuncBody();
    for (size_t i = 0; i < stmt_list_size; ++i) {
        if (func_body[i].GetKind() == NodeKind::Initialization) {
            auto &decl = dynamic_cast<const InitializationNode &>(func_body[i]).GetVarToInit();
            declarations.emplace_back(std::make_shared<VarDeclNode>(decl));
            context.Add(GetValue(decl, object_ptr_));
            if (!context.IsEmpty())
                break;
        }
    }
    return declarations;
}

void SemanticAnalyzer::UndoDeclarations(const std::vector<std::shared_ptr<VarDeclNode>> &declarations) {
    for (auto &decl: declarations) {
        object_ptr_->DeleteVar(decl->GetName());
    }
}

std::unique_ptr<FunctionSymbol> SemanticAnalyzer::CreateFuncSymbol(const FuncDeclNode &node, SemanticErrorContext &context) {
    std::unique_ptr<FunctionSymbol> returned_symbol = nullptr;
    std::vector<VarSymbol> params;
    for (const auto &param: node.GetFuncParams())
        params.emplace_back(CreateVarSymbol(*param));
    auto declarations = MakeDeclarations(node, context);
    if (context.IsEmpty()) {
        auto return_type = TypeResolver::GetValue(node.GetFuncBody(), object_ptr_);
        if (return_type.index() == 1) {
            context.Add(std::move(std::get<1>(return_type)));
        } else {
            returned_symbol = std::make_unique<FunctionSymbol>(node.GetFuncName(), std::get<0>(return_type),
                                                               std::move(params));
        }
    }
    UndoDeclarations(declarations);
    return returned_symbol;
}

void SemanticAnalyzer::Visit(const AssignNode &node) {
    SemanticErrorContext context;
    context.Add(GetValue(node.GetLeft(), object_ptr_));
    context.Add(GetValue(node.GetRight(), object_ptr_));
    if (context.IsEmpty())
        ChecksPerformer<AssignNode>::PerformChecks(node, *object_ptr_, context);
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const VarDeclNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<VarDeclNode>::PerformChecks(node, *object_ptr_, context);
    if (context.IsEmpty()) {
        object_ptr_->InsertSymbol(CreateVarSymbol(node));
    }
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const VarReferenceNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<VarReferenceNode>::PerformChecks(node, *object_ptr_, context);
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const SignedLiteralNode &node) {
    Return(SemanticErrorContext{});
}

void SemanticAnalyzer::Visit(const UnsignedLiteralNode &node) {
    Return(SemanticErrorContext{});
}

void SemanticAnalyzer::Visit(const CellLiteralNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<CellLiteralNode>::PerformChecks(node, *object_ptr_, context);
    Return(std::move(context));
}

    void SemanticAnalyzer::Visit(const InitializationNode &node) {
    SemanticErrorContext context;
    context.Add(GetValue(node.GetVarToInit(), object_ptr_));
    if(!node.InitExprIsEmpty())
        context.Add(GetValue(node.GetInitExpr(), object_ptr_));
    ChecksPerformer<InitializationNode>::PerformChecks(node, *object_ptr_, context);
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const StatementListNode &node) {
    SemanticErrorContext context;
    for(size_t i = 0; i < node.NumOfStatements(); ++i){
        context.Add(GetValue(node[i], object_ptr_));
    }
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const BinaryOpNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<BinaryOpNode>::PerformChecks(node, *object_ptr_, context);
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const UnaryOpNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<UnaryOpNode>::PerformChecks(node, *object_ptr_, context);
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const IfNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<IfNode>::PerformChecks(node, *object_ptr_, context);
    if (context.IsEmpty()) {
        object_ptr_->AddNewScope("IF_CLAUSE of " + object_ptr_->GetCurrentScopeName(),
                                 object_ptr_->GetCurrentScopeLevel() + 1);
        context.Add(GetValue(node.GetBody(), object_ptr_));
        object_ptr_->RemoveCurrentScope();
    }
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const WhileNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<WhileNode>::PerformChecks(node, *object_ptr_, context);
    if (context.IsEmpty()) {
        object_ptr_->AddNewScope("WHILE_CLAUSE of" + object_ptr_->GetCurrentScopeName(),
                                 object_ptr_->GetCurrentScopeLevel() + 1);
        context.Add(GetValue(node.GetBody(), object_ptr_));
        object_ptr_->RemoveCurrentScope();
    }
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const FuncDeclNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<FuncDeclNode>::PerformChecks(node, *object_ptr_, context);
    if (context.IsEmpty()) {
        object_ptr_->AddNewScope(node.GetFuncName(), object_ptr_->GetCurrentScopeLevel() + 1);
        for (auto &param: node.GetFuncParams())
            context.Add(GetValue(*param, object_ptr_));
        std::unique_ptr<FunctionSymbol> func_symbol;
        if (context.IsEmpty())
            func_symbol = CreateFuncSymbol(node, context);
        if (context.IsEmpty()) {
            object_ptr_->InsertSymbol(std::move(*func_symbol));
            context.Add(GetValue(node.GetFuncBody(), object_ptr_));
        }
        object_ptr_->RemoveCurrentScope();
    }
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const FuncCallNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<FuncCallNode>::PerformChecks(node, *object_ptr_, context);
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const MatrixElementReferenceNode &node) {
    SemanticErrorContext context;
    ChecksPerformer<VarReferenceNode>::PerformChecks(static_cast<const VarReferenceNode &>(node),
                                                     *object_ptr_,
                                                     context);
    if (context.IsEmpty()) {
        context.Add(GetValue(node.GetHorizontalIndex(), object_ptr_));
        context.Add(GetValue(node.GetVerticalIndex(), object_ptr_));
    }
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const XrayNode &node) {
    Return(SemanticErrorContext{});
}

void SemanticAnalyzer::Visit(const PrintNode &node) {
    SemanticErrorContext context;
    auto print_expr_type = TypeResolver::GetValue(node, object_ptr_);
    if (print_expr_type.index() == 1) {
        context.Add(std::move(std::get<1>(print_expr_type)));
    }
    Return(std::move(context));
}

void SemanticAnalyzer::Visit(const RobotMoveNode &node) {
    Return(SemanticErrorContext{});
}