#include "signed_value.h"
#include "value.h"
#include "cell.h"

SignedValue::SignedValue(int value): IValue({TypeToken::Signed}), ValueHolder<int>(value) {}

Value SignedValue::Equal(const IValue &other) const {
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
            equal = value_ == static_cast<int>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    if (equal)
        return SignedValue(1);
    else
        return SignedValue(0);
}

Value SignedValue::Less(const IValue &other) const {
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
            less = value_ < static_cast<int>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    if (less)
        return SignedValue(1);
    else
        return SignedValue(0);
}

Value SignedValue::Greater(const IValue &other) const {
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
            greater = value_ > static_cast<int>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    if (greater)
        return SignedValue(1);
    else
        return SignedValue(0);
}

Value SignedValue::Minus(const IValue &other) const {
    auto other_type = other.GetType();
    int result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ - std::any_cast<int>(other.GetValue());
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ - static_cast<int>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ - static_cast<int>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return SignedValue(result);
}

Value SignedValue::Plus(const IValue &other) const {
    auto other_type = other.GetType();
    int result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ + std::any_cast<int>(other.GetValue());
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ + static_cast<int>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ + static_cast<int>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return SignedValue(result);
}

Value SignedValue::Star(const IValue &other) const {
    auto other_type = other.GetType();
    int result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ * std::any_cast<int>(other.GetValue());
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ * static_cast<int>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ * static_cast<int>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return SignedValue(result);
}

Value SignedValue::Slash(const IValue &other) const {
    auto other_type = other.GetType();
    int result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ / std::any_cast<int>(other.GetValue());
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ / static_cast<int>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ / static_cast<int>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return SignedValue(result);
}

Value SignedValue::Percent(const IValue &other) const {
    auto other_type = other.GetType();
    int result;
    switch (other_type.GetSimpleType()) {
        case TypeToken::Signed: {
            result = value_ % std::any_cast<int>(other.GetValue());
            break;
        }
        case TypeToken::Unsigned: {
            result = value_ % static_cast<int>(std::any_cast<unsigned>(other.GetValue()));
            break;
        }
        case TypeToken::Cell: {
            result = value_ % static_cast<int>(std::any_cast<Cell>(other.GetValue()));
            break;
        }
    }
    return SignedValue(result);
}

Value SignedValue::Hash() const {
    throw std::logic_error("Cannot apply '#' operator to Signed type");
}

Value SignedValue::UnaryMinus() const {
    return SignedValue(-value_);
}

Value SignedValue::UnaryPlus() const {
    return SignedValue(value_);
}

Value &SignedValue::SubscriptOperator(const IValue &line, const IValue &column) {
    throw std::logic_error("Cannot apply subscript operator to non-matrix type");
}

std::any SignedValue::GetValue() const {
    return std::make_any<int>(value_);
}

void SignedValue::SetValue(Value &&new_value) {
    auto type = new_value->GetType();
    switch (type.GetSimpleType()) {
        case TypeToken::Signed: {
            value_ = std::any_cast<int>(new_value->GetValue());
            return;
        }
        case TypeToken::Unsigned: {
            value_ = static_cast<int>(std::any_cast<unsigned>(new_value->GetValue()));
            return;
        }
        case TypeToken::Cell: {
            value_ = static_cast<int>(std::any_cast<Cell>(new_value->GetValue()));
        }
    }
}

void SignedValue::PrintOut(std::ostream &stream) const {
    stream << value_;
}