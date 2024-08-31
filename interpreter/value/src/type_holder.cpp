#include "type_holder.h"

TypeHolder::TypeHolder(TypeToken simple_type_token) {
    if (simple_type_token != TypeToken::Matrix)
        type_.emplace(type_.begin(), simple_type_token);
    else
        throw std::logic_error("cannot start type with non built-in type");
}

void TypeHolder::MakeMatrixWrap() {
    type_.emplace(type_.begin(), TypeToken::Matrix);
}

void TypeHolder::MakeConst() noexcept {
    const_qualified_ = true;
}

TypeHolderWrapper::TypeHolderWrapper(const TypeHolder &type_holder) {
    type_ = type_holder.type_;
    const_qualified_ = type_holder.const_qualified_;
}

TypeHolderWrapper::TypeHolderWrapper(std::vector<TypeToken> &&type, bool const_qualified)
    : type_(std::move(type)), const_qualified_(const_qualified) {}

bool TypeHolderWrapper::IsSameAs(const TypeHolderWrapper &other) const noexcept {
    return type_ == other.type_;
}

bool TypeHolderWrapper::IsSimpleType() const noexcept {
    return type_.size() == 1;
}

bool TypeHolderWrapper::IsCellType() const noexcept {
    return IsSimpleType() && GetSimpleType() == TypeToken::Cell;
}

bool TypeHolderWrapper::IsNumericType() const noexcept {
    return IsSimpleType() && !IsCellType();
}

bool TypeHolderWrapper::IsConvertibleTo(const TypeHolderWrapper &other) const noexcept {
    if (type_.size() == other.type_.size()) {
        if (IsSimpleType()) {
            return (IsNumericType() || IsCellType()) && (other.IsNumericType() || other.IsCellType());
        } else {
            return GetInnerType().IsConvertibleTo(other.GetInnerType());
        }
    }
    return false;
}

TypeToken TypeHolderWrapper::GetSimpleType() const {
    return type_.back();
}

TypeHolderWrapper TypeHolderWrapper::GetInnerType() const {
    if (!IsSimpleType()) {
        std::vector<TypeToken> inner_type{type_.begin() + 1, type_.end()};
        return {std::move(inner_type), const_qualified_};
    } else
        throw std::logic_error("Cannot get inner type for simple type");
}

bool TypeHolderWrapper::IsConst() const noexcept {
    return const_qualified_;
}

std::string TypeHolderWrapper::GetStringForTypeToken(TypeToken token) noexcept {
    switch (token) {
        case TypeToken::Signed:
            return {"signed"};
        case TypeToken::Unsigned:
            return {"unsigned"};
        case TypeToken::Cell:
            return {"Cell"};
        case TypeToken::Matrix:
            return {"matrix"};
    }
}

std::string TypeHolderWrapper::GetStringRepresentation() const noexcept {
    std::string repr;
    if (type_.empty())
        repr = "None";
    for (auto token: type_) {
        repr += '<' + GetStringForTypeToken(token) + '>';
    }
    return repr;
}