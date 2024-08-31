#include "xray_node.h"
#include "node_visitor.h"

XrayNode::XrayNode(const INode::location_t &loc): INode(NodeKind::XrayNode, loc) {}

void XrayNode::PrintOut(std::ostream &stream) const {
    stream << "XrayNode\n";
}

void XrayNode::Accept(NodeVisitor &visitor) const {
    visitor.Visit(*this);
}