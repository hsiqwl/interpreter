#include "../include/parsing_driver.h"
#include "../include/grammar.tab.hh"

ParsingDriver::ParsingDriver()
    : trace_parsing(false), trace_scanning(false), error_count_(0) {}

bool ParsingDriver::Parse(const std::string &filename) {
    file = filename;
    location.initialize(&filename);
    if (!ScanBegin())
        return false;
    yy::parser parser(*this);
    parser.set_debug_level(trace_parsing);
    parser.parse();
    ScanEnd();
    return true;
}

void ParsingDriver::SetTraceScanning(bool tracing) {
    trace_scanning = tracing;
}

void ParsingDriver::SetTraceParsing(bool tracing) {
    trace_parsing = tracing;
}

const yy::location &ParsingDriver::GetLocation() const {
    return location;
}

void ParsingDriver::LocationStep() {
    location.step();
}

void ParsingDriver::MoveLocationColumn(int columns) {
    location.columns(columns);
}

void ParsingDriver::MoveLocationLine(int lines) {
    location.lines(lines);
}

void ParsingDriver::DetectError() noexcept {
    ++error_count_;
}

bool ParsingDriver::NoSyntacticErrors() const noexcept {
    return error_count_ == 0;
}