#include "var.h"

VarSymbol::VarSymbol(std::string_view name, const TypeHolderWrapper &type, bool is_const)
    : Symbol(name), type_(type), const_qualifier_(is_const) {}

bool VarSymbol::IsConst() const {
    return const_qualifier_;
}

const TypeHolderWrapper& VarSymbol::GetType() const {
    return type_;
}
