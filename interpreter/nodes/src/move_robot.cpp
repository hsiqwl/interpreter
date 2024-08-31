#include "move_robot.h"
#include "node_visitor.h"

RobotMoveNode::RobotMoveNode(const INode::location_t &loc, MoveDirection direction)
: INode(NodeKind::RobotMoveNode, loc), direction_(direction) {}

void RobotMoveNode::Accept(NodeVisitor &visitor) const {
    visitor.Visit(*this);
}

void RobotMoveNode::PrintOut(std::ostream &stream) const {
    stream << "RobotMoveNode";
}

MoveDirection RobotMoveNode::GetMoveDirection() const noexcept {
    return direction_;
}
