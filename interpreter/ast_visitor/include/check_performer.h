#ifndef INTERPRETER_SEMANTIC_ANALYZER_HELPERS_H
#define INTERPRETER_SEMANTIC_ANALYZER_HELPERS_H
#include "type_resolver.h"
#include "semantic_error_context.h"
#include "node_traits.h"
#include <algorithm>

template <typename NodeType>
class ChecksPerformer{
public:
    static void PerformChecks(const NodeType& node, SymbolTableManager& manager, SemanticErrorContext& context) { static_assert(false, "Cannot instantiate checker for unknown type of node");}
};

template<>
class ChecksPerformer<VarDeclNode> {
public:
    static void PerformChecks(const VarDeclNode& node, SymbolTableManager& manager, SemanticErrorContext& context) {
        if (manager.VarDeclaredInCurrentScope(node.GetName())) {
            auto &var = manager.GetVar(node.GetName());
            if (var.GetType().IsSameAs(node.GetType()))
                context.Add(std::make_shared<RedeclarationOfIdentifier>(node.GetLocation(), node.GetName()));
            else
                context.Add(std::make_shared<ConflictingDeclaration>(node.GetLocation(), node.GetName()));
        }
        if (!node.GetType().IsSimpleType()) {
            CheckIndexes(node.GetHorizontalSize(), manager, context);
            CheckIndexes(node.GetVerticalSize(), manager, context);
        }
    }

private:
    static void CheckIndexes(const INode& index, SymbolTableManager& manager, SemanticErrorContext& context){
        auto index_type = TypeResolver::GetValue(index, &manager);
        if(index_type.index() == 1) {
            context.Add(std::move(std::get<1>(index_type)));
        } else if(!std::get<0>(index_type).IsConvertibleTo(TypeHolderWrapper{TypeToken::Unsigned})){
            context.Add(std::make_shared<NoKnownConversion>(index.GetLocation(),
                                                            std::get<0>(index_type),
                                                            TypeHolderWrapper{TypeToken::Unsigned}));
        }
    }
};


template <>
class ChecksPerformer<FuncDeclNode> {
public:
    static void PerformChecks(const FuncDeclNode& node, SymbolTableManager& manager, SemanticErrorContext& context) {
        if (manager.FuncDeclared(node.GetFuncName()))
            context.Add(std::make_shared<RedeclarationOfIdentifier>(node.GetLocation(), node.GetFuncName()));
    }
};

template <>
class ChecksPerformer<FuncCallNode> {
public:
    static void PerformChecks(const FuncCallNode &node, SymbolTableManager &manager, SemanticErrorContext &context) {
        if (!manager.FuncDeclared(node.GetFuncName())) {
            context.Add(std::make_shared<CallToUndeclaredFunction>(node.GetLocation(), node.GetFuncName()));
        } else if (!CorrectNumberOfArguments(node, manager.GetFunc(node.GetFuncName()))) {
            context.Add(std::make_shared<IncorrectNumberOfArguments>(node.GetLocation(), node.GetFuncName(),
                                                                     manager.GetFunc(
                                                                             node.GetFuncName()).GetParamNumber(),
                                                                     node.GetArgs().size()));
        } else {
            auto &func_symbol = manager.GetFunc(node.GetFuncName());
            for (auto iter = node.GetArgs().begin(), end = node.GetArgs().end(); iter != end; ++iter) {
                auto arg_type = TypeResolver::GetValue(**iter, &manager);
                auto &param_type = func_symbol.GetParamByIndex(std::distance(node.GetArgs().begin(), iter)).GetType();
                if (arg_type.index() == 1 || !std::get<0>(arg_type).IsConvertibleTo(param_type)) {
                    context.Add(std::make_shared<ArgumentsOfIncorrectType>(node.GetLocation(), node.GetFuncName(),
                                                                           param_type, std::get<0>(arg_type)));
                    return;
                }
            }
        }
    }

private:
    static bool CorrectNumberOfArguments(const FuncCallNode &node, const FunctionSymbol &symbol) {
        return node.GetArgs().size() == symbol.GetParamNumber();
    }
};

template<>
class ChecksPerformer<AssignNode> {
public:
    static void PerformChecks(const AssignNode& node, SymbolTableManager& manager, SemanticErrorContext& context) {
        auto lhs_type = TypeResolver::GetValue(node.GetLeft(), &manager);
        if (lhs_type.index() == 1) {
            context.Add(std::move(std::get<1>(lhs_type)));
            return;
        }
        auto rhs_type = TypeResolver::GetValue(node.GetRight(), &manager);
        if (rhs_type.index() == 1) {
            context.Add(std::move(std::get<1>(rhs_type)));
            return;
        }
        if (std::get<0>(lhs_type).IsConst()) {
            context.Add(std::make_shared<AssignmentOfConstVar>(node.GetLocation()));
            return;
        }
        if (!std::get<0>(rhs_type).IsConvertibleTo(std::get<0>(lhs_type))) {
            context.Add(std::make_shared<NoKnownConversion>(node.GetLocation(), std::get<0>(rhs_type), std::get<0>(lhs_type)));
            return;
        }
    }
};

template<>
class ChecksPerformer<VarReferenceNode> {
public:
    static void PerformChecks(const VarReferenceNode& node, SymbolTableManager& manager, SemanticErrorContext& context) {
        bool var_declared = manager.VarDeclaredInSomeScope(node.GetVarName());
        bool func_declared = manager.FuncDeclared(node.GetVarName());
        if (!(var_declared || func_declared)) {
            context.Add(std::make_shared<UseOfUndeclaredIdentifier>(node.GetLocation(), node.GetVarName()));
        } else if (!var_declared) {
            context.Add(std::make_shared<InvalidIdentifierUsage>(node.GetLocation(), node.GetVarName()));
        }
    }
};

template <>
class ChecksPerformer<InitializationNode> {
public:
    static void
    PerformChecks(const InitializationNode &node, SymbolTableManager &manager, SemanticErrorContext &context) {
        auto lhs_type = TypeResolver::GetValue(node.GetVarToInit(), &manager);
        if (lhs_type.index() == 1) {
            context.Add(std::move(std::get<1>(lhs_type)));
            return;
        }
        auto &lhs_type_wrapper = std::get<0>(lhs_type);
        if (lhs_type_wrapper.IsConst() && node.InitExprIsEmpty()) {
            context.Add(
                    std::make_shared<UninitializedConstVariable>(node.GetLocation(), node.GetVarToInit().GetName()));
            return;
        }
        if (!node.InitExprIsEmpty()) {
            auto rhs_type = TypeResolver::GetValue(node.GetInitExpr(), &manager);
            if (rhs_type.index() == 1) {
                context.Add(std::move(std::get<1>(rhs_type)));
                return;
            }
            if (!std::get<0>(rhs_type).IsConvertibleTo(lhs_type_wrapper))
                context.Add(std::make_shared<NoKnownConversion>(node.GetLocation(), std::get<0>(rhs_type),
                                                                lhs_type_wrapper));
        }
    }
};

template<>
class ChecksPerformer<UnaryOpNode> {
private:
    static bool CorrectOperandType(UnaryOpKind op_kind, const TypeHolderWrapper& type) {
        switch (op_kind) {
            case UnaryOpKind::Hash: {
                if (!type.IsSimpleType() && !type.GetInnerType().IsSimpleType())
                    return false;
                return true;
            }
            default:
                return true;
        }
    }

public:
    static void
    PerformChecks(const UnaryOpNode &node, SymbolTableManager &manager, SemanticErrorContext &context) {
        auto operand_type = TypeResolver::GetValue(node, &manager);
        if (operand_type.index() == 1) {
            context.Add(std::move(std::get<1>(operand_type)));
        } else if (!CorrectOperandType(node.GetOpKind(), std::get<0>(operand_type))) {
            context.Add(std::make_shared<InvalidOperandTypes>(node.GetLocation()));
        }
    }
};

template<>
class ChecksPerformer<BinaryOpNode> {
private:
    static bool DividingByZero(const INode &rhs) {
        auto rhs_ptr = dynamic_cast<const Literal *>(&rhs);
        if (rhs_ptr == nullptr)
            return false;
        else if (rhs_ptr->GetValue()->GetType().GetSimpleType() == TypeToken::Signed)
            return std::any_cast<int>(rhs_ptr->GetValue()->GetValue()) == 0;
        else
            return std::any_cast<unsigned>(rhs_ptr->GetValue()->GetValue()) == 0;
    }

    static bool CorrectOperationForSimpleType(BinaryOpKind kind, TypeToken lhs_type) {
        if (lhs_type == TypeToken::Cell)
            return kind == BinaryOpKind::Minus || kind == BinaryOpKind::Slash || kind == BinaryOpKind::Percent;
        else
            return true;
    }

    static bool CorrectOperandTypes(BinaryOpKind kind, const TypeHolderWrapper &lhs, const TypeHolderWrapper &rhs) {
        if (!lhs.IsSimpleType() && !rhs.IsSimpleType()) {
            if (kind == BinaryOpKind::Equal || kind == BinaryOpKind::Greater || kind == BinaryOpKind::Less)
                return false;
            auto lhs_inner = lhs.GetInnerType();
            auto rhs_inner = rhs.GetInnerType();
            return CorrectOperandTypes(kind, lhs_inner, rhs_inner);
        } else if (!lhs.IsSimpleType() && rhs.IsSimpleType()) {
            if (kind == BinaryOpKind::Equal || kind == BinaryOpKind::Greater || kind == BinaryOpKind::Less)
                return false;
            auto lhs_inner = lhs.GetInnerType();
            return CorrectOperandTypes(kind, lhs_inner, rhs);
        } else if (lhs.IsSimpleType() && rhs.IsSimpleType()) {
            return CorrectOperationForSimpleType(kind, lhs.GetSimpleType());
        } else
            return false;
    }

public:
    static void
    PerformChecks(const BinaryOpNode &node, SymbolTableManager &manager, SemanticErrorContext &context) {
        auto resolved_type = TypeResolver::GetValue(node, &manager);
        if (resolved_type.index() == 1) {
            context.Add(std::move(std::get<1>(resolved_type)));
            return;
        }
        auto lhs_type = std::get<0>(TypeResolver::GetValue(node.GetLeft(), &manager));
        auto rhs_type = std::get<0>(TypeResolver::GetValue(node.GetRight(), &manager));
        if (!CorrectOperandTypes(node.GetOpKind(), lhs_type, rhs_type)) {
            context.Add(std::make_shared<InvalidOperandTypes>(node.GetLocation()));
            return;
        }
        if (node.GetOpKind() == BinaryOpKind::Slash && DividingByZero(node.GetRight())) {
            context.Add(std::make_shared<DivisionByZero>(node.GetLocation()));
            return;
        }
    }
};

template<>
class ChecksPerformer<IfNode> {
public:
    static void PerformChecks(const IfNode& node, SymbolTableManager& manager, SemanticErrorContext& context) {
        auto acceptable_predicate_type = TypeHolderWrapper{TypeToken::Signed};
        auto actual_predicate_type = TypeResolver::GetValue(node.GetPredicate(), &manager);
        if (actual_predicate_type.index() == 1) {
            context.Add(std::move(std::get<1>(actual_predicate_type)));
            return;
        }
        if (!std::get<0>(actual_predicate_type).IsConvertibleTo(acceptable_predicate_type))
            context.Add(std::make_shared<NoKnownConversion>(node.GetLocation(), std::get<0>(actual_predicate_type), acceptable_predicate_type));
    }
};

template<>
class ChecksPerformer<WhileNode> {
public:
    static void PerformChecks(const WhileNode& node, SymbolTableManager& manager, SemanticErrorContext& context) {
        auto acceptable_predicate_type = TypeHolderWrapper{TypeToken::Signed};
        auto actual_predicate_type = TypeResolver::GetValue(node.GetPredicate(), &manager);
        if (actual_predicate_type.index() == 1) {
            context.Add(std::move(std::get<1>(actual_predicate_type)));
            return;
        }
        if (!std::get<0>(actual_predicate_type).IsConvertibleTo(acceptable_predicate_type))
            context.Add(std::make_shared<NoKnownConversion>(node.GetLocation(), std::get<0>(actual_predicate_type), acceptable_predicate_type));
    }
};

template <>
class ChecksPerformer<CellLiteralNode> {
public:
    static void PerformChecks(const CellLiteralNode& node, SymbolTableManager& manager, SemanticErrorContext& context) {
        if (!NoContradictions(node)) {
            context.Add(std::make_shared<ConflictingValues>(node.GetLocation()));
        }
        if (!NoDuplicates(node)) {
            context.Add(std::make_shared<DuplicateValues>(node.GetLocation()));
            return;
        }
    }

private:
    static bool NoDuplicates(const CellLiteralNode& node) {
        bool no_duplicates;
        no_duplicates = NoDuplicateForWallPlaceholder(node, WallPlaceholder::top);
        no_duplicates = no_duplicates && NoDuplicateForWallPlaceholder(node, WallPlaceholder::ntop);
        no_duplicates = no_duplicates && NoDuplicateForWallPlaceholder(node, WallPlaceholder::ndown);
        no_duplicates = no_duplicates && NoDuplicateForWallPlaceholder(node, WallPlaceholder::down);
        no_duplicates = no_duplicates && NoDuplicateForWallPlaceholder(node, WallPlaceholder::left);
        no_duplicates = no_duplicates && NoDuplicateForWallPlaceholder(node, WallPlaceholder::nleft);
        no_duplicates = no_duplicates && NoDuplicateForWallPlaceholder(node, WallPlaceholder::right);
        no_duplicates = no_duplicates && NoDuplicateForWallPlaceholder(node, WallPlaceholder::nright);
        return no_duplicates;
    }

    static bool NoDuplicateForWallPlaceholder(const CellLiteralNode& node, WallPlaceholder placeholder) {
        size_t duplicates;
        duplicates = std::count(node.GetInitList().begin(), node.GetInitList().end(), placeholder);
        if(duplicates > 1)
            return false;
        return true;
    };

    static bool NoContradictions(const CellLiteralNode& node) {
        size_t wall_exists, wall_no_exist;
        wall_exists = std::count(node.GetInitList().begin(), node.GetInitList().end(), WallPlaceholder::top);
        wall_no_exist = std::count(node.GetInitList().begin(), node.GetInitList().end(), WallPlaceholder::ntop);
        if (wall_exists != 0 && wall_no_exist != 0)
            return false;
        wall_exists = std::count(node.GetInitList().begin(), node.GetInitList().end(), WallPlaceholder::down);
        wall_no_exist = std::count(node.GetInitList().begin(), node.GetInitList().end(), WallPlaceholder::ndown);
        if (wall_exists != 0 && wall_no_exist != 0)
            return false;
        wall_exists = std::count(node.GetInitList().begin(), node.GetInitList().end(), WallPlaceholder::left);
        wall_no_exist = std::count(node.GetInitList().begin(), node.GetInitList().end(), WallPlaceholder::nleft);
        if (wall_exists != 0 && wall_no_exist != 0)
            return false;
        wall_exists = std::count(node.GetInitList().begin(), node.GetInitList().end(), WallPlaceholder::right);
        wall_no_exist = std::count(node.GetInitList().begin(), node.GetInitList().end(), WallPlaceholder::nright);
        if (wall_exists != 0 && wall_no_exist != 0)
            return false;
        return true;
    }
};

#endif //INTERPRETER_SEMANTIC_ANALYZER_HELPERS_H
