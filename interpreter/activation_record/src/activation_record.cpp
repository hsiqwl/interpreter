#include "activation_record.h"

ActivationRecord::ActivationRecord(std::string_view record_name)
    :record_name_(record_name) {}

Value &ActivationRecord::GetValue(const std::string &var_name) {
    return records_.at(var_name);
}

bool ActivationRecord::AssociatedValueExists(const std::string &var_name) {
    return records_.contains(var_name);
}

const std::string &ActivationRecord::GetRecordName() const noexcept {
    return record_name_;
}

void ActivationRecord::PutValue(const std::string &var_name, Value &&value) {
    if (records_.contains(var_name))
        records_[var_name]->SetValue(std::move(value));
    else
        records_.emplace(var_name, std::move(value));
}