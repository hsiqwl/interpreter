#include "node_traits.h"
#include "printer.h"

void AstPrinter::Visit(const UnaryOpNode &node) {
    node.GetOperand().Accept(*this);
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const BinaryOpNode &node) {
    node.GetLeft().Accept(*this);
    node.GetRight().Accept(*this);
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const VarDeclNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const VarReferenceNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const AssignNode &node) {
    node.GetLeft().Accept(*this);
    node.GetRight().Accept(*this);
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const StatementListNode &node) {
    node.PrintOut(*buf_);
    for (auto stmt_i = 0; stmt_i < node.NumOfStatements(); ++stmt_i) {
        (*buf_) << "PROCESSING NEW STATEMENT\n";
        node[stmt_i].Accept(*this);
        (*buf_) << "END OF STATEMENT\n";
    }
    (*buf_) << "END OF ALL STATEMENTS\n";
}

void AstPrinter::Visit(const SignedLiteralNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const UnsignedLiteralNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const InitializationNode &node) {
    node.GetVarToInit().Accept(*this);
    if(!node.InitExprIsEmpty())
        node.GetInitExpr().Accept(*this);
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const IfNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const WhileNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const FuncCallNode &node) {
    node.PrintOut(*buf_);
    for (const auto &arg: node.GetArgs()) {
        *buf_ << "arg:";
        arg->Accept(*this);
    }
    *buf_ << '\n';
}

void AstPrinter::Visit(const FuncDeclNode &node) {
    node.PrintOut(*buf_);
    *buf_ << "parameters:\n";
    for (const auto &param: node.GetFuncParams()) {
        param->Accept(*this);
    }
    *buf_ << "function body:\n";
    node.GetFuncBody().Accept(*this);
}

void AstPrinter::Visit(const CellLiteralNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const MatrixElementReferenceNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const XrayNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const RobotMoveNode &node) {
    node.PrintOut(*buf_);
}

void AstPrinter::Visit(const PrintNode &node) {
    node.PrintOut(*buf_);
    node.GetExprToPrint().Accept(*this);
}