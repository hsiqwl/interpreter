#include "execution_context.h"

CallStack &ExecutionContext::GetCallStack() {
    return stack_;
}

const FuncDeclNode &ExecutionContext::GetFunc(const std::string &name) const {
    return *functions_.at(name);
}

ExecutionContext::global_statements_iterator ExecutionContext::GetGlobalStatementsBegin() const {
    return global_statements_.begin();
}

ExecutionContext::global_statements_iterator ExecutionContext::GetGlobalStatementsEnd() const {
    return global_statements_.end();
}