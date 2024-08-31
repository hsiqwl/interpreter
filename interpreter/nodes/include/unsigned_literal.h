#ifndef INTERPRETER_UNSIGNED_LITERAL_H
#define INTERPRETER_UNSIGNED_LITERAL_H
#include "literal.h"
#include "unsigned_value.h"
#include "value.h"
#include "printable_interface.h"

class UnsignedLiteralNode: public Literal, public IPrintable{
public:
    UnsignedLiteralNode(unsigned value, const location_t &loc);

    Value GetValue() const noexcept override;

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

private:
    UnsignedValue value_;
};

#endif //INTERPRETER_UNSIGNED_LITERAL_H
