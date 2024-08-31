#ifndef INTERPRETER_EXECUTOR_H
#define INTERPRETER_EXECUTOR_H
#include "node_interface.h"
#include "node_visitor.h"
#include "value_getter.h"
#include "sharable_object_holder.h"
#include "execution_context.h"
#include <optional>
#include "cell_value.h"
#include "matrix_value.h"
#include "remote_environment_handler.h"
#include "exe_env_ostream_loader.h"

class Executor: public SharableObjectHolder<ExecutionContext>,
                public ValueGetterWithSharableObjectHolder
                     <
                     Executor,
                     INode,
                     std::optional<Value>
                     >,
                public NodeVisitor {
public:
    Executor(ExecutionContext* context);

    void Visit(const BinaryOpNode& node) override;

    void Visit(const UnaryOpNode& node) override;

    void Visit(const VarDeclNode& node) override;

    void Visit(const VarReferenceNode& node) override;

    void Visit(const AssignNode& node) override;

    void Visit(const StatementListNode& node) override;

    void Visit(const SignedLiteralNode& node) override;

    void Visit(const UnsignedLiteralNode& node) override;

    void Visit(const InitializationNode& node) override;

    void Visit(const IfNode& node) override;

    void Visit(const WhileNode& node) override;

    void Visit(const FuncDeclNode& node) override;

    void Visit(const FuncCallNode& node) override;

    void Visit(const CellLiteralNode& node) override;

    void Visit(const XrayNode& node) override;

    void Visit(const MatrixElementReferenceNode& node) override;

    void Visit(const PrintNode& node) override;

    void Visit(const RobotMoveNode& node) override;

private:
    Value GetDefaultValue(const VarDeclNode& node);

    Value GetDefaultValueAccordingToType(const TypeHolderWrapper& type);

    void PassArguments(const FuncDeclNode& node, std::vector<Value>&& args);

    std::vector<Value> PrepareArguments(const FuncCallNode& node);

    static bool PredicateEvaluatesToTrue(Value& predicate_value);
};

#endif //INTERPRETER_EXECUTOR_H
