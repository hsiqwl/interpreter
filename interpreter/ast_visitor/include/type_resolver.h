#ifndef INTERPRETER_TYPE_RESOLVER_H
#define INTERPRETER_TYPE_RESOLVER_H
#include "node_interface.h"
#include "node_visitor.h"
#include "value_getter.h"
#include "type_holder.h"
#include "sharable_object_holder.h"
#include "sym_tab_manager.h"
#include "var.h"
#include "function.h"
#include "semantic_error.h"
#include <variant>

using TypeResolverReturnValue = std::variant<TypeHolderWrapper, std::shared_ptr<SemanticError>>;

class TypeResolver: public SharableObjectHolder<SymbolTableManager>,
                    public ValueGetterWithSharableObjectHolder
                    <
                    TypeResolver,
                    INode,
                    TypeResolverReturnValue
                    >,
                    public NodeVisitor{
public:
    TypeResolver(SymbolTableManager* manager);

    void Visit(const BinaryOpNode& node) override;

    void Visit(const UnaryOpNode& node) override;

    void Visit(const VarDeclNode& node) override;

    void Visit(const VarReferenceNode& node) override;

    void Visit(const AssignNode& node) override;

    void Visit(const StatementListNode& node) override;

    void Visit(const SignedLiteralNode& node) override;

    void Visit(const UnsignedLiteralNode& node) override;

    void Visit(const CellLiteralNode& node) override;

    void Visit(const InitializationNode& node) override;

    void Visit(const IfNode& node) override;

    void Visit(const WhileNode& node) override;

    void Visit(const FuncDeclNode& node) override;

    void Visit(const FuncCallNode& node) override;

    void Visit(const XrayNode& node) override;

    void Visit(const RobotMoveNode& node) override;

    void Visit(const MatrixElementReferenceNode& node) override;

    void Visit(const PrintNode& node) override;
};

#endif //INTERPRETER_TYPE_RESOLVER_H
