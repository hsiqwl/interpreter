#ifndef INTERPRETER_MOVE_ROBOT_H
#define INTERPRETER_MOVE_ROBOT_H
#include "node_interface.h"
#include "printable_interface.h"
#include "robot.h"

class RobotMoveNode: public INode, public IPrintable {
public:
    RobotMoveNode(const location_t& loc, MoveDirection direction);

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream & stream) const override;

    MoveDirection GetMoveDirection() const noexcept;

private:
    MoveDirection direction_;
};

#endif //INTERPRETER_MOVE_ROBOT_H
