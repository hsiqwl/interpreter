#ifndef INTERPRETER_ENUMS_H
#define INTERPRETER_ENUMS_H

enum class NodeKind{
    BinaryOp,
    UnaryOp,
    SignedLiteral,
    UnsignedLiteral,
    CellLiteral,
    VarDecl,
    VarRef,
    Assign,
    Initialization,
    StatementList,
    IfNode,
    WhileNode,
    FuncDecl,
    FuncCall,
    XrayNode,
    RobotMoveNode,
    PrintNode
};

enum class BinaryOpKind{
    Plus,
    Minus,
    Star,
    Slash,
    Less,
    Greater,
    Equal,
    Percent
};

enum class UnaryOpKind{
    Plus,
    Minus,
    Hash
};

#endif //INTERPRETER_ENUMS_H
