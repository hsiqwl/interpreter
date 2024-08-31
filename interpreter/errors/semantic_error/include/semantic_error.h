#ifndef INTERPRETER_SEMANTIC_ERROR_H
#define INTERPRETER_SEMANTIC_ERROR_H
#include <stdexcept>
#include "location.hh"
#include <boost/format.hpp>
#include "type_holder.h"

class SemanticError: public std::exception {
protected:
    std::string msg_;

public:
    const char * what() const noexcept override;

    virtual ~SemanticError() = default;
};

class UseOfUndeclaredIdentifier: public SemanticError{
public:
    UseOfUndeclaredIdentifier(const yy::location& loc, std::string_view id);
};

class InvalidIdentifierUsage: public SemanticError {
public:
    InvalidIdentifierUsage(const yy::location& loc, std::string_view id);
};

class RedeclarationOfIdentifier: public SemanticError{
public:
    RedeclarationOfIdentifier(const yy::location& loc, std::string_view id);
};

class ConflictingDeclaration: public SemanticError {
public:
    ConflictingDeclaration(const yy::location& loc, std::string_view id);
};

class InvalidOperandTypes: public SemanticError{
public:
    InvalidOperandTypes(const yy::location& loc);
};

class AssignmentOfConstVar: public SemanticError{
public:
    AssignmentOfConstVar(const yy::location& loc);
};

class NoKnownConversion: public SemanticError{
public:
    NoKnownConversion(const yy::location& loc, const TypeHolderWrapper& from, const TypeHolderWrapper& to);
};

class CallToUndeclaredFunction: public SemanticError{
public:
    CallToUndeclaredFunction(const yy::location& loc, std::string_view id);
};

class IncorrectNumberOfArguments: public SemanticError{
public:
    IncorrectNumberOfArguments(const yy::location& loc, std::string_view id, size_t expected, size_t actual);
};

class ArgumentsOfIncorrectType: public SemanticError{
public:
    ArgumentsOfIncorrectType(const yy::location& loc, std::string_view id, const TypeHolderWrapper& expected, const TypeHolderWrapper& actual);
};

class UninitializedConstVariable: public SemanticError {
public:
    UninitializedConstVariable(const yy::location& loc, std::string_view id);
};

class DivisionByZero: public SemanticError {
public:
    DivisionByZero(const yy::location& loc);
};

class InfiniteRecursiveCall: public SemanticError {
public:
    InfiniteRecursiveCall(const yy::location& loc, std::string_view func_name);
};

class CellLiteralInitError: public SemanticError {};

class DuplicateValues: public CellLiteralInitError{
public:
    DuplicateValues(const yy::location& loc);
};

class ConflictingValues: public CellLiteralInitError {
public:
    ConflictingValues(const yy::location& loc);
};
#endif //INTERPRETER_SEMANTIC_ERROR_H
