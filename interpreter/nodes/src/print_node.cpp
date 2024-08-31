#include "print_node.h"
#include "node_visitor.h"

PrintNode::PrintNode(std::unique_ptr<INode> &&expr, const INode::location_t &loc)
: INode(NodeKind::PrintNode, loc), expr_to_print_(std::move(expr)) {}

void PrintNode::Accept(NodeVisitor &visitor) const {
    visitor.Visit(*this);
}

const INode &PrintNode::GetExprToPrint() const {
    return *expr_to_print_;
}

void PrintNode::PrintOut(std::ostream &stream) const {
    stream << "PrintNode for expr:\n";
}