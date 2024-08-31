#include "unsigned_value.h"
#include "value.h"
#include "cell.h"

UnsignedValue::UnsignedValue(unsigned value): IValue({TypeToken::Unsigned}), ValueHolder<unsigned>(value) {}

Value UnsignedValue::Equal(const IValue &other) const {
    auto other_type = other.GetType();
    bool equal = false;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            equal = value_ == std::any_cast<int>(other.GetValue());
            break;
        }
        case TypeToken::Unsigned: {
            equal = value_ == std::any_cast<unsigned>(other.GetValue());
            break;
        }
        case TypeToken::Cell: {
            equal = value_ == static_cast<unsigned>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    if (equal)
        return UnsignedValue(1);
    else
        return UnsignedValue(0);
}

Value UnsignedValue::Less(const IValue &other) const {
    auto other_type = other.GetType();
    bool less = false;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            less = value_ < std::any_cast<int>(other.GetValue());
            break;
        }
        case TypeToken::Unsigned: {
            less = value_ < std::any_cast<unsigned>(other.GetValue());
            break;
        }
        case TypeToken::Cell: {
            less = value_ < static_cast<unsigned>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    if (less)
        return UnsignedValue(1);
    else
        return UnsignedValue(0);
}

Value UnsignedValue::Greater(const IValue &other) const {
    auto other_type = other.GetType();
    bool greater = false;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            greater = value_ > std::any_cast<int>(other.GetValue());
            break;
        }
        case TypeToken::Unsigned: {
            greater = value_ > std::any_cast<unsigned>(other.GetValue());
            break;
        }
        case TypeToken::Cell: {
            greater = value_ > static_cast<unsigned>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    if (greater)
        return UnsignedValue(1);
    else
        return UnsignedValue(0);
}

Value UnsignedValue::Minus(const IValue &other) const {
    auto other_type = other.GetType();
    unsigned result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ - static_cast<unsigned>(std::any_cast<int>(other.GetValue()));
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ - static_cast<unsigned>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ - static_cast<unsigned>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return UnsignedValue(result);
}

Value UnsignedValue::Plus(const IValue &other) const {
    auto other_type = other.GetType();
    unsigned result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ + static_cast<unsigned>(std::any_cast<int>(other.GetValue()));
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ + static_cast<unsigned>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ + static_cast<unsigned>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return UnsignedValue(result);
}

Value UnsignedValue::Star(const IValue &other) const {
    auto other_type = other.GetType();
    unsigned result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ * static_cast<unsigned>(std::any_cast<int>(other.GetValue()));
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ * static_cast<unsigned>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ * static_cast<unsigned>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return UnsignedValue(result);
}

Value UnsignedValue::Slash(const IValue &other) const {
    auto other_type = other.GetType();
    unsigned result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ / static_cast<unsigned>(std::any_cast<int>(other.GetValue()));
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ / static_cast<unsigned>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ / static_cast<unsigned>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return UnsignedValue(result);
}

Value UnsignedValue::Percent(const IValue &other) const {
    auto other_type = other.GetType();
    unsigned result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ % static_cast<unsigned>(std::any_cast<int>(other.GetValue()));
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ % static_cast<unsigned>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ % static_cast<unsigned>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return UnsignedValue(result);
}

Value UnsignedValue::Hash() const {
    throw std::logic_error("Cannot apply '#' operator to Unsigned type");
}

Value UnsignedValue::UnaryPlus() const {
    return SignedValue(static_cast<int>(value_));
}

Value UnsignedValue::UnaryMinus() const {
    return SignedValue(-static_cast<int>(value_));
}

Value &UnsignedValue::SubscriptOperator(const IValue &line, const IValue &column) {
    throw std::logic_error("Cannot apply subscript operator to non-matrix type");
}

std::any UnsignedValue::GetValue() const {
    return std::make_any<unsigned>(value_);
}

void UnsignedValue::SetValue(Value &&new_value) {
    auto type = new_value->GetType();
    switch (type.GetSimpleType()) {
        case TypeToken::Signed: {
            value_ = static_cast<unsigned>(std::any_cast<int>(new_value->GetValue()));
            return;
        }
        case TypeToken::Unsigned: {
            value_ = static_cast<unsigned >(std::any_cast<unsigned>(new_value->GetValue()));
            return;
        }
        case TypeToken::Cell: {
            value_ = static_cast<unsigned>(std::any_cast<Cell>(new_value->GetValue()));
        }
    }
}

void UnsignedValue::PrintOut(std::ostream &stream) const {
    stream << value_;
}