#ifndef INTERPRETER_EXECUTOR_CALLER_H
#define INTERPRETER_EXECUTOR_CALLER_H
#include "executor.h"
#include "ast.h"

class ExecutorCaller {
public:
    ExecutorCaller(const Ast& tree);

    std::optional<Value> CallExecutor();

private:
    void ExecuteGlobalStatements();

    ExecutionContext context_;
};

#endif //INTERPRETER_EXECUTOR_CALLER_H
