#ifndef INTERPRETER_VAR_H
#define INTERPRETER_VAR_H
#include "symbol.h"
#include "type_holder.h"

class VarSymbol: public Symbol{
private:
    TypeHolderWrapper type_;

    bool const_qualifier_;

public:
    VarSymbol(std::string_view name, const TypeHolderWrapper &type, bool is_const = false);

    const TypeHolderWrapper& GetType() const;

    bool IsConst() const;
};


#endif //INTERPRETER_VAR_H
