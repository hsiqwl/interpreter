#ifndef INTERPRETER_EXECUTION_CONTEXT_BUILDER_H
#define INTERPRETER_EXECUTION_CONTEXT_BUILDER_H
#include "execution_context.h"
#include "ast.h"

class ExecutionContextBuilder {
public:
    static ExecutionContext Build(const Ast &tree);
};

#endif //INTERPRETER_EXECUTION_CONTEXT_BUILDER_H
