#ifndef INTERPRETER_CALL_STACK_H
#define INTERPRETER_CALL_STACK_H
#include "activation_record.h"
#include <vector>
#include <ranges>

class CallStack {
private:
    std::vector<ActivationRecord> stack_;

    ActivationRecord& GetClosestRecordForName(const std::string& var_name);

public:
    CallStack();

    void CreateNewFrame(std::string_view record_name = "Global");

    void RemoveCurrentFrame();

    const std::string& GetCurrentFrameName() const noexcept;

    Value& GetValue(const std::string& name);

    void PutValue(const std::string& name, Value&& value);

    void RegisterValue(const std::string& name, Value&& value);
};

#endif //INTERPRETER_CALL_STACK_H
