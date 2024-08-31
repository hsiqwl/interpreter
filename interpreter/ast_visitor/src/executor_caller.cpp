#include "executor_caller.h"
#include "execution_context_builder.h"

ExecutorCaller::ExecutorCaller(const Ast &tree): context_(ExecutionContextBuilder::Build(tree)) {}

std::optional<Value> ExecutorCaller::CallExecutor() {
    try {
        ExecuteGlobalStatements();
        auto &entry_point = context_.GetFunc("start");
        context_.GetCallStack().CreateNewFrame("start");
        return Executor::GetValue(entry_point.GetFuncBody(), &context_);
    } catch (std::out_of_range &ex) {
        return std::nullopt;
    }
}

void ExecutorCaller::ExecuteGlobalStatements() {
    for(auto iter = context_.GetGlobalStatementsBegin(), end = context_.GetGlobalStatementsEnd(); iter != end; ++iter){
        Executor::GetValue(**iter, &context_);
    }
}