#include "robot_commands.h"

RobotCommand::RobotCommand(Robot &receiver): receiver_(&receiver) {}

RobotMoveCommand::RobotMoveCommand(Robot &receiver, MoveDirection direction)
: RobotCommand(receiver), direction_(direction) {}

bool RobotMoveCommand::HasAccumulatedValue() const noexcept {
    return false;
}

std::any RobotMoveCommand::GetAccumulatedValue() const {
    throw std::runtime_error("After this command there is no accumulated value stored");
}

void RobotMoveCommand::Run() {
    receiver_->Move(direction_);
}