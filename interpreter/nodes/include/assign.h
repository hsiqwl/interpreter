#ifndef INTERPRETER_ASSIGN_H
#define INTERPRETER_ASSIGN_H
#include "node_interface.h"
#include "var_ref.h"
#include "printable_interface.h"

class AssignNode: public INode, public IPrintable{
public:
    AssignNode(std::unique_ptr<VarReferenceNode> &&lhs, std::unique_ptr<INode> &&rhs, const location_t &loc);

    [[nodiscard]] const VarReferenceNode &GetLeft() const noexcept;

    [[nodiscard]] const INode &GetRight() const noexcept;

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

private:
    std::shared_ptr<VarReferenceNode> lhs_;

    std::shared_ptr<INode> rhs_;
};

#endif //INTERPRETER_ASSIGN_H
