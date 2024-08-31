#ifndef INTERPRETER_ROBOT_COMMANDS_H
#define INTERPRETER_ROBOT_COMMANDS_H
#include "command.h"
#include "robot.h"
#include <stdexcept>

class RobotCommand: public Command {
public:
    RobotCommand(Robot& receiver);

    virtual ~RobotCommand() = default;

protected:
    Robot* receiver_;
};

class RobotMoveCommand: public RobotCommand {
public:
    RobotMoveCommand(Robot& receiver, MoveDirection direction);

    void Run() override;

    bool HasAccumulatedValue() const noexcept override;

    std::any GetAccumulatedValue() const override;

private:
    MoveDirection direction_;
};

#endif //INTERPRETER_ROBOT_COMMANDS_H
