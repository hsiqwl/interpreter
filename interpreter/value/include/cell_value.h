#ifndef INTERPRETER_CELL_VALUE_H
#define INTERPRETER_CELL_VALUE_H
#include "value_holder.h"
#include "value_interface.h"
#include "unsigned_value.h"
#include "cell.h"

class CellValue: public IValue, public ValueHolder<Cell> {
public:
    CellValue(Cell value = Cell{});

    Value Equal(const IValue &other) const override;

    Value Less(const IValue &other) const override;

    Value Greater(const IValue &other) const override;

    Value Plus(const IValue &other) const override;

    Value Minus(const IValue &other) const override;

    Value Star(const IValue &other) const override;

    Value Slash(const IValue &other) const override;

    Value Percent(const IValue &other) const override;

    Value Hash() const override;

    Value UnaryMinus() const override;

    Value UnaryPlus() const override;

    void SetValue(Value &&new_value) override;

    Value& SubscriptOperator(const IValue& line, const IValue& column) override;

    [[nodiscard]] std::any GetValue() const override;

    void PrintOut(std::ostream &stream) const override;
};
#endif //INTERPRETER_CELL_VALUE_H
