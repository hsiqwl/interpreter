#ifndef INTERPRETER_TYPE_HOLDER_H
#define INTERPRETER_TYPE_HOLDER_H
#include "type_token.h"
#include <vector>
#include <variant>
#include <stdexcept>

class TypeHolderWrapper;

class TypeHolder{
private:
    std::vector<TypeToken> type_;

    bool const_qualified_ = false;

    friend class TypeHolderWrapper;

public:
    TypeHolder() = default;

    TypeHolder(TypeToken simple_type_token);

    void MakeMatrixWrap();

    void MakeConst() noexcept;
};


class TypeHolderWrapper{
private:
    std::vector<TypeToken> type_;

    bool const_qualified_ = false;

    bool IsNumericType() const noexcept;

    bool IsCellType() const noexcept;

    static std::string GetStringForTypeToken(TypeToken token) noexcept;

    TypeHolderWrapper(std::vector<TypeToken>&& type, bool const_qualified);

public:
    TypeHolderWrapper(const TypeHolder& type_holder);

    TypeHolderWrapper() = default;

    bool IsSameAs(const TypeHolderWrapper& other) const noexcept;

    bool IsConvertibleTo(const TypeHolderWrapper& other) const noexcept;

    [[nodiscard]] bool IsSimpleType() const noexcept;

    [[nodiscard]] TypeToken GetSimpleType() const;

    TypeHolderWrapper GetInnerType() const;

    bool IsConst() const noexcept;

    std::string GetStringRepresentation() const noexcept;
};
#endif //INTERPRETER_TYPE_HOLDER_H
