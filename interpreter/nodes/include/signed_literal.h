#ifndef INTERPRETER_SIGNED_LITERAL_H
#define INTERPRETER_SIGNED_LITERAL_H
#include "literal.h"
#include "signed_value.h"
#include "value.h"
#include "printable_interface.h"

class SignedLiteralNode: public Literal, public IPrintable{
public:
    SignedLiteralNode(int value, const location_t &loc);

    Value GetValue() const noexcept override;

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

private:
    SignedValue value_;
};

#endif //INTERPRETER_SIGNED_LITERAL_H
