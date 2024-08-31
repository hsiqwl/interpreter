#ifndef INTERPRETER_EXECUTION_CONTEXT_H
#define INTERPRETER_EXECUTION_CONTEXT_H
#include "call_stack.h"
#include "func_decl.h"
#include "func_call.h"

class ExecutionContextBuilder;


class ExecutionContext {
private:
    std::vector<const INode*> global_statements_;

    std::unordered_map<std::string, const FuncDeclNode*> functions_;

    CallStack stack_;

    ExecutionContext() = default;

    friend class ExecutionContextBuilder;

public:
    typedef std::vector<const INode*>::const_iterator global_statements_iterator;

    CallStack& GetCallStack();

    const FuncDeclNode& GetFunc(const std::string& name) const;

    global_statements_iterator GetGlobalStatementsBegin() const;

    global_statements_iterator GetGlobalStatementsEnd() const;
};

#endif //INTERPRETER_EXECUTION_CONTEXT_H
