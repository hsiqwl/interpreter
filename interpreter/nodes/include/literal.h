#ifndef INTERPRETER_LITERAL_H
#define INTERPRETER_LITERAL_H
#include "node_interface.h"
#include "value.h"

class Literal: public INode {
public:
    Literal(NodeKind kind, const location_t &loc) : INode(kind, loc) {}

    virtual Value GetValue() const noexcept = 0;

    virtual ~Literal() = default;
};

#endif //INTERPRETER_LITERAL_H
