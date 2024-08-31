#include "cell_value.h"
#include "value.h"

CellValue::CellValue(Cell value): IValue({TypeToken::Cell}), ValueHolder<Cell>(value) {}

Value CellValue::Equal(const IValue &other) const {
    throw std::logic_error("cannot apply '=' operation on Cell type");
}

Value CellValue::Less(const IValue &other) const {
    throw std::logic_error("cannot apply '<' operation on Cell type");
}

Value CellValue::Greater(const IValue &other) const {
    throw std::logic_error("cannot apply '>' operation on Cell type");
}

Value CellValue::Minus(const IValue &other) const {
    auto type = other.GetType();
    switch (type.GetSimpleType()) {
        case TypeToken::Signed: {
            return CellValue(value_ - static_cast<Cell>(std::any_cast<int>(other.GetValue())));
        }
        case TypeToken::Unsigned: {
            return CellValue(value_ - static_cast<Cell>(std::any_cast<unsigned>(other.GetValue())));
        }
        case TypeToken::Cell: {
            return CellValue(value_ - std::any_cast<Cell>(other.GetValue()));
        }
    }
}

Value CellValue::Plus(const IValue &other) const {
    throw std::logic_error("cannot apply '+' operation on Cell type");
}

Value CellValue::Star(const IValue &other) const {
    throw std::logic_error("cannot apply '*' operation on Cell type");
}

Value CellValue::Slash(const IValue &other) const {
    auto type = other.GetType();
    switch (type.GetSimpleType()) {
        case TypeToken::Signed: {
            return CellValue(value_ / static_cast<Cell>(std::any_cast<int>(other.GetValue())));
        }
        case TypeToken::Unsigned: {
            return CellValue(value_ / static_cast<Cell>(std::any_cast<unsigned>(other.GetValue())));
        }
        case TypeToken::Cell: {
            return CellValue(value_ / std::any_cast<Cell>(other.GetValue()));
        }
    }
}

Value CellValue::Percent(const IValue &other) const {
    auto type = other.GetType();
    switch (type.GetSimpleType()) {
        case TypeToken::Signed: {
            return CellValue(value_ % static_cast<Cell>(std::any_cast<int>(other.GetValue())));
        }
        case TypeToken::Unsigned: {
            return CellValue(value_ % static_cast<Cell>(std::any_cast<unsigned>(other.GetValue())));
        }
        case TypeToken::Cell: {
            return CellValue(value_ % std::any_cast<Cell>(other.GetValue()));
        }
    }
}

Value CellValue::Hash() const {
    throw std::logic_error("Cannot apply '#' operator to Cell type");
}

Value CellValue::UnaryPlus() const {
    Value converted = UnsignedValue{static_cast<unsigned>(value_)};
    return converted->UnaryPlus();
}

Value CellValue::UnaryMinus() const {
    Value converted = SignedValue{static_cast<int>(value_)};
    return converted->UnaryMinus();
}

Value &CellValue::SubscriptOperator(const IValue &line, const IValue &column) {
    throw std::logic_error("Cannot apply subscript operator to non-matrix type");
}

std::any CellValue::GetValue() const {
    return std::make_any<Cell>(value_);
}

void CellValue::SetValue(Value &&new_value) {
    switch (new_value->GetType().GetSimpleType()) {
        case TypeToken::Signed: {
            value_ = static_cast<Cell>(std::any_cast<int>(new_value->GetValue()));
            return;
        }
        case TypeToken::Unsigned: {
            value_ = static_cast<Cell>(std::any_cast<unsigned>(new_value->GetValue()));
            return;
        }
        case TypeToken::Cell: {
            value_ = std::any_cast<Cell>(new_value->GetValue());
            return;
        }
    }
}

void CellValue::PrintOut(std::ostream &stream) const {
    auto str = (boost::format("<Cell> walls: top -> %1%, bottom -> %2%, left -> %3%, right -> %4%")
            % value_.WallExists(Direction::top) % value_.WallExists(Direction::down)
            % value_.WallExists(Direction::left) % value_.WallExists(Direction::right)).str();
    stream << str;
}