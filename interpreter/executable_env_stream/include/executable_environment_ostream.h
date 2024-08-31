#ifndef INTERPRETER_EXECUTABLE_ENVIRONMENT_OSTREAM_H
#define INTERPRETER_EXECUTABLE_ENVIRONMENT_OSTREAM_H
#include <fstream>
#include "value.h"
#include <string>

class ExecutableEnvironmentOutputStream {
public:
    ExecutableEnvironmentOutputStream(std::string buffer_name);

    void Eat(const Value& value_to_print);

private:
    std::string buffer_name_;
};

#endif //INTERPRETER_EXECUTABLE_ENVIRONMENT_OSTREAM_H
