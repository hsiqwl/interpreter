#ifndef INTERPRETER_COMMAND_H
#define INTERPRETER_COMMAND_H
#include <any>

class Command {
public:
    virtual void Run() = 0;

    virtual bool HasAccumulatedValue() const noexcept = 0;

    virtual std::any GetAccumulatedValue() const = 0;

    virtual ~Command() = default;
};

#endif //INTERPRETER_COMMAND_H
