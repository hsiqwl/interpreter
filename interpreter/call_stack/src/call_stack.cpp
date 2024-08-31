#include "call_stack.h"

CallStack::CallStack() {
    CreateNewFrame();
}

void CallStack::CreateNewFrame(std::string_view record_name) {
    stack_.emplace_back(record_name);
}

void CallStack::RemoveCurrentFrame() {
    stack_.pop_back();
}

const std::string &CallStack::GetCurrentFrameName() const noexcept {
    return stack_.back().GetRecordName();
}

ActivationRecord &CallStack::GetClosestRecordForName(const std::string &var_name) {
    for (auto &activation_record: std::ranges::reverse_view(stack_))
        if (activation_record.AssociatedValueExists(var_name))
            return activation_record;
}

void CallStack::PutValue(const std::string &name, Value &&value) {
    GetClosestRecordForName(name).PutValue(name, std::move(value));
}

Value &CallStack::GetValue(const std::string &name) {
    return GetClosestRecordForName(name).GetValue(name);
}

void CallStack::RegisterValue(const std::string &name, Value &&value) {
    stack_.back().PutValue(name, std::move(value));
}