#ifndef INTERPRETER_SYMBOL_H
#define INTERPRETER_SYMBOL_H
#include <string>
#include <string_view>
#include <fstream>

class Symbol{
protected:
    std::string name_;

public:
    Symbol(std::string_view name);

    const std::string& GetName() const;

    virtual ~Symbol() = default;
};

#endif //INTERPRETER_SYMBOL_H
