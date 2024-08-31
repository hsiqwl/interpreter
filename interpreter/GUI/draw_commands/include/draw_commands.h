#ifndef INTERPRETER_DRAW_COMMANDS_H
#define INTERPRETER_DRAW_COMMANDS_H
#include "command.h"
#include "robot.h"
#include "map.h"

class DrawCommand: public Command {
public:
    DrawCommand(const Map& map, const Robot& robot);

    virtual ~DrawCommand() = default;

    void Run() override;

    bool HasAccumulatedValue() const noexcept override;

    std::any GetAccumulatedValue() const override;

protected:
    const Map* map_;

    const Robot* robot_;
};

#endif //INTERPRETER_DRAW_COMMANDS_H
