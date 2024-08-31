#include "interpreter.h"

void Interpreter::SetLogStream(std::ostream &ostream) {
    log_stream_ = &ostream;
}

void Interpreter::Run(std::string_view file_name) {
    ParsingDriver driver;
    if (!driver.Parse(std::string(file_name))) {
        *log_stream_ << "Cannot open file with name: " << file_name << '\n';
        return;
    }
    if (driver.NoSyntacticErrors()) {
        SemanticAnalyzerCaller semantic_analyzer;
        auto semantic_errors = semantic_analyzer.CallAnalyzer(driver.tree_);
        if (semantic_errors.IsEmpty()) {
            ExecutorCaller executor(driver.tree_);
            executor.CallExecutor();
        } else {
            semantic_errors.PrintOut(*log_stream_);
        }
    }
}