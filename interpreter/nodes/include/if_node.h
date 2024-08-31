#ifndef INTERPRETER_IF_NODE_H
#define INTERPRETER_IF_NODE_H
#include "node_interface.h"
#include "printable_interface.h"

class IfNode: public INode, public IPrintable {
public:
    IfNode(std::unique_ptr<INode> &&predicate, std::unique_ptr<INode> &&body, const location_t &loc);

    const INode& GetPredicate() const noexcept;

    const INode& GetBody() const noexcept;

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

private:
    std::shared_ptr<INode> predicate_;

    std::shared_ptr<INode> body_;
};

#endif //INTERPRETER_IF_NODE_H
