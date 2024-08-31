#ifndef INTERPRETER_PRINTABLE_INTERFACE_H
#define INTERPRETER_PRINTABLE_INTERFACE_H
#include <iostream>
#include <format>
#include <boost/format.hpp>

class IPrintable {
public:
   virtual void PrintOut(std::ostream &stream) const = 0;
};

#endif //INTERPRETER_PRINTABLE_INTERFACE_H
