#ifndef INTERPRETER_BINARY_OP_H
#define INTERPRETER_BINARY_OP_H
#include "node_interface.h"
#include "printable_interface.h"

class BinaryOpNode: public INode, public IPrintable{
public:
    BinaryOpNode(BinaryOpKind op_kind, std::unique_ptr<INode> &&lhs, std::unique_ptr<INode> &&rhs,
                 const location_t &loc);

    void Accept(NodeVisitor& visitor) const override;

    [[nodiscard]] const INode& GetLeft() const noexcept;

    [[nodiscard]] const INode& GetRight() const noexcept;

    [[nodiscard]] BinaryOpKind GetOpKind() const noexcept;

    void PrintOut(std::ostream& stream) const override;

private:
    BinaryOpKind op_kind_;

    std::shared_ptr<INode> lhs_;

    std::shared_ptr<INode> rhs_;

    char GetLabel() const;
};

#endif //INTERPRETER_BINARY_OP_H
