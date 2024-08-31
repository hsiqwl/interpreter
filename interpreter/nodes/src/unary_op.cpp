#include "unary_op.h"
#include "node_visitor.h"

char UnaryOpNode::GetLabel() const{
    switch (op_kind_) {
        case UnaryOpKind::Plus: {
            return '+';
        }
        case UnaryOpKind::Minus:{
            return '-';
        }
        case UnaryOpKind::Hash:{
            return '#';
        }
    }
}

UnaryOpNode::UnaryOpNode(UnaryOpKind op_kind, std::unique_ptr<INode> &&operand, const location_t &loc)
    : INode(NodeKind::UnaryOp, loc), operand_(std::move(operand)), op_kind_(op_kind) {}

void UnaryOpNode::Accept(NodeVisitor &visitor) const{
    visitor.Visit(*this);
}

UnaryOpKind UnaryOpNode::GetOpKind() const noexcept {
    return op_kind_;
}

const INode &UnaryOpNode::GetOperand() const noexcept {
    return *operand_;
}

void UnaryOpNode::PrintOut(std::ostream &stream) const {
    auto fmt_string = std::format("UnaryOpNode : '{}'", GetLabel());
    stream << fmt_string << '\n';
}