#ifndef INTERPRETER_MATRIX_VALUE_H
#define INTERPRETER_MATRIX_VALUE_H
#include "value_interface.h"
#include "value.h"
#include "unsigned_value.h"
#include "cell_value.h"
#include "value_holder.h"
#include <vector>

class MatrixValue: public IValue, public ValueHolder<std::vector<std::vector<Value>>> {
public:
    using matrix_t = std::vector<std::vector<Value>>;

    MatrixValue(Value& contained_value, const TypeHolderWrapper& type);

    MatrixValue(Value max_horizontal_index, Value max_vertical_index, Value& contained_value, const TypeHolderWrapper& type);

    MatrixValue(size_t max_horizontal_index, size_t max_vertical_index, const TypeHolderWrapper& type, Value& contained_value);

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

    Value& SubscriptOperator(const IValue& line, const IValue& column) override;

    Value& GetElement(size_t i, size_t j);

    const Value& GetElement(size_t i, size_t j) const;

    void SetValue(Value &&new_value) override;

    [[nodiscard]] std::any GetValue() const override;

    void PrintOut(std::ostream &stream) const override;

    size_t Lines() const noexcept;

    size_t Columns() const noexcept;

private:
    static Cell GetCellValue(const IValue& value);

    static size_t GetNumericValue(const IValue& value);

    MatrixValue MakeIntersectionWith(const MatrixValue& other) const;

    void HashForNumericElements(MatrixValue &matrix) const;

    void HashForCellElements(MatrixValue& matrix) const;

    void ExpandCellMatrixTemporary();

    void ShrinkCellMatrix();

    void PrintOutForNumeric(std::ostream& stream) const;

    void PrintOutForNonNumeric(std::ostream& stream) const;

    void PrintOutForCell(std::ostream& steam) const;
};

#endif //INTERPRETER_MATRIX_VALUE_H
