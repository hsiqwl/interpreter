#ifndef INTERPRETER_PARSING_DRIVER_H
#define INTERPRETER_PARSING_DRIVER_H

#include <string>
#include <cstddef>
#include "grammar.tab.hh"
#include "ast.h"

#define YY_DECL yy::parser::symbol_type yylex (ParsingDriver& drv)

YY_DECL;

class ParsingDriver {
public:
    ParsingDriver();

    bool Parse(const std::string &filename);

    [[nodiscard]] const yy::location &GetLocation() const;

    void SetTraceParsing(bool tracing);

    void SetTraceScanning(bool tracing);

    void MoveLocationLine(int lines = 1);

    void MoveLocationColumn(int columns = 1);

    void LocationStep();

    Ast tree_;

    void DetectError() noexcept;

    bool NoSyntacticErrors() const noexcept;

private:
    size_t error_count_;

    std::string file;

    bool trace_parsing;

    bool ScanBegin();

    void ScanEnd();

    bool trace_scanning;

    yy::location location;
};
#endif //! INTERPRETER_PARSING_DRIVER_H
