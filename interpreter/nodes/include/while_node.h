#ifndef INTERPRETER_WHILE_NODE_H
#define INTERPRETER_WHILE_NODE_H
#include "node_interface.h"
#include "printable_interface.h"

class WhileNode: public INode, public IPrintable{
public:
    WhileNode(std::unique_ptr<INode> &&predicate, std::unique_ptr<INode> &&body, const location_t &loc);

    const INode& GetPredicate() const noexcept;

    const INode& GetBody() const noexcept;

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

private:
    std::shared_ptr<INode> predicate_;

    std::shared_ptr<INode> body_;
};

#endif //INTERPRETER_WHILE_NODE_H
