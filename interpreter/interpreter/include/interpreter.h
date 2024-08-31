#ifndef INTERPRETER_INTERPRETER_H
#define INTERPRETER_INTERPRETER_H
#include "parsing_driver.h"
#include "semantic_analyzer_caller.h"
#include "executor_caller.h"

class Interpreter {
public:
    void Run(std::string_view file_name);

    void SetLogStream(std::ostream& ostream = std::cout);

private:
    std::ostream* log_stream_ = nullptr;
};

#endif //INTERPRETER_INTERPRETER_H
