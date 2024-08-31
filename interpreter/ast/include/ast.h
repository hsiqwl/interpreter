#ifndef INTERPRETER_AST_H
#define INTERPRETER_AST_H
#include "node_traits.h"

class Ast {
private:
    std::shared_ptr<INode> root_;

public:
    Ast() = default;

    Ast(std::unique_ptr<INode> &&node);

    const INode& GetRoot() const;
};

#endif //INTERPRETER_AST_H
