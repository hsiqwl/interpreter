#include "execution_context_builder.h"

ExecutionContext ExecutionContextBuilder::Build(const Ast &tree) {
    ExecutionContext context;
    auto &stmt_list = dynamic_cast<const StatementListNode &>(tree.GetRoot());
    for (size_t i = 0; i < stmt_list.NumOfStatements(); ++i) {
        auto func_decl_ptr = dynamic_cast<const FuncDeclNode *>(&stmt_list[i]);
        if (func_decl_ptr != nullptr) {
            std::string func_name = func_decl_ptr->GetFuncName();
            context.functions_.emplace(std::move(func_name), func_decl_ptr);
        } else {
            context.global_statements_.emplace_back(&stmt_list[i]);
        }
    }
    return context;
}