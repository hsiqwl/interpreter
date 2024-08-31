#ifndef INTERPRETER_VALUE_GETTER_H
#define INTERPRETER_VALUE_GETTER_H
#include <type_traits>
#include "sharable_object_holder.h"

template<typename VisitorImpl, typename Node, typename ResultType>
requires (!std::is_void_v<ResultType>)
class ValueGetterWithSharableObjectHolder{
public:
    template<typename SharableObject>
    static ResultType GetValue(const Node& node, SharableObject* ptr){
        VisitorImpl visitor(ptr);
        node.Accept(visitor);
        return visitor.value_;
    }

    void Return(ResultType value){
        value_ = std::move(value);
    }

private:
    ResultType value_;
};

#endif //INTERPRETER_VALUE_GETTER_H
