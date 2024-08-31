#include "executable_environment_ostream.h"

ExecutableEnvironmentOutputStream::ExecutableEnvironmentOutputStream(std::string buffer_name)
: buffer_name_(std::move(buffer_name)) {}

void ExecutableEnvironmentOutputStream::Eat(const Value &value_to_print) {
    if (buffer_name_.empty()) {
        value_to_print->PrintOut(std::cout);
    } else {
        std::fstream fstream(buffer_name_, std::ios::app);
        value_to_print->PrintOut(fstream);
    }
}