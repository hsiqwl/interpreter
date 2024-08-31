#include "semantic_analyzer_caller.h"

SemanticErrorContext SemanticAnalyzerCaller::CallAnalyzer(const Ast &tree) {
    return SemanticAnalyzer::GetValue(tree.GetRoot(), &symbol_table_);
}