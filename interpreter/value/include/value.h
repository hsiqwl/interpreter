#ifndef INTERPRETER_VALUE_H
#define INTERPRETER_VALUE_H
#include <any>
#include <concepts>
#include <stdexcept>
#include "value_interface.h"

class Value{
public:
    template <std::derived_from<IValue> ConcreteValue>
    Value(ConcreteValue&& value)
        : storage_(std::forward<ConcreteValue>(value)),
          getter_([](std::any& storage) -> IValue& {
              return std::any_cast<ConcreteValue&>(storage);}),
          const_getter([](const std::any& storage) -> const IValue& {
              return std::any_cast<const ConcreteValue&>(storage);
          }) {}

    Value(): storage_(), getter_([](std::any&) -> IValue& {
        throw std::runtime_error("Usage of uninitialized value");}),
        const_getter([](const std::any&) -> const IValue& {
            throw std::runtime_error("Usage of uninitialized value");})
        {}

    IValue* operator -> () {return &getter_(storage_);}

    IValue& operator * () {return getter_(storage_);}

    const IValue& operator * () const {return const_getter(storage_);}

    const IValue* operator -> () const {return &const_getter(storage_);}

private:
    std::any storage_;

    IValue& (*getter_)(std::any&);

    const IValue& (*const_getter)(const std::any&);
};

#endif //INTERPRETER_VALUE_H
