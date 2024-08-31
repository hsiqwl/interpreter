#include "ast.h"

Ast::Ast(std::unique_ptr<INode> &&node) : root_(std::move(node)) {}

const INode &Ast::GetRoot() const {
    return *root_;
}
