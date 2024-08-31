#ifndef INTERPRETER_VALUE_INTERFACE_H
#define INTERPRETER_VALUE_INTERFACE_H
#include <memory>
#include <any>
#include <stdexcept>
#include "type_holder.h"
#include "printable_interface.h"

class Value;

class IValue: public IPrintable{
public:
    IValue(const TypeHolderWrapper& type) : type_(type) {}

    TypeHolderWrapper GetType() const noexcept { return type_; }

    virtual Value Equal(const IValue &other) const = 0;

    virtual Value Less(const IValue &other) const = 0;

    virtual Value Greater(const IValue &other) const = 0;

    virtual Value Plus(const IValue &other) const = 0;

    virtual Value Minus(const IValue &other) const = 0;

    virtual Value Star(const IValue &other) const = 0;

    virtual Value Slash(const IValue &other) const = 0;

    virtual Value Percent(const IValue &other) const = 0;

    virtual Value Hash() const = 0;

    virtual Value UnaryMinus() const = 0;

    virtual Value UnaryPlus() const = 0;

    virtual Value& SubscriptOperator(const IValue& line, const IValue& column) = 0;

    virtual void SetValue(Value&& new_value) = 0;

    [[nodiscard]] virtual std::any GetValue() const = 0;

    virtual ~IValue() = default;

private:
    TypeHolderWrapper type_;
};

#endif //INTERPRETER_VALUE_INTERFACE_H
