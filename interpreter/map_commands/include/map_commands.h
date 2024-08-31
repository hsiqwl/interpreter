#ifndef INTERPRETER_MAP_COMMANDS_H
#define INTERPRETER_MAP_COMMANDS_H
#include "command.h"
#include "map.h"
#include "robot.h"
#include "matrix_value.h"

class MapVisionCommand: public Command {
public:
    MapVisionCommand(const Map& receiver, const Robot& robot);

    void Run() override;

    bool HasAccumulatedValue() const noexcept override;

    std::any GetAccumulatedValue() const override;

private:
    const Map* receiver_;

    size_t line_number_, column_number_;

    Map accumulated_value_;
};

#endif //INTERPRETER_MAP_COMMANDS_H
