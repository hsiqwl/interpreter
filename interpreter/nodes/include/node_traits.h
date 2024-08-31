#ifndef INTERPRETER_NODE_TRAITS_H
#define INTERPRETER_NODE_TRAITS_H
#include "enums.h"
#include "binary_op.h"
#include "unary_op.h"
#include "signed_literal.h"
#include "unsigned_literal.h"
#include "var_ref.h"
#include "var_decl.h"
#include "assign.h"
#include "initialization.h"
#include "statement_list.h"
#include "if_node.h"
#include "while_node.h"
#include "func_decl.h"
#include "func_call.h"
#include "cell_literal.h"
#include <type_traits>
#include "xray_node.h"
#include "print_node.h"
#include "move_robot.h"

template<NodeKind Kind>
struct node_type_from_kind;

#define MAKE_NODE_TRAITS(t, kind) \
template <> struct node_type_from_kind<kind> \
{                                    \
    using type = t;                              \
}

MAKE_NODE_TRAITS(BinaryOpNode, NodeKind::BinaryOp);

MAKE_NODE_TRAITS(UnaryOpNode, NodeKind::UnaryOp);

MAKE_NODE_TRAITS(VarReferenceNode, NodeKind::VarRef);

MAKE_NODE_TRAITS(VarDeclNode, NodeKind::VarDecl);

MAKE_NODE_TRAITS(AssignNode, NodeKind::Assign);

MAKE_NODE_TRAITS(StatementListNode, NodeKind::StatementList);

MAKE_NODE_TRAITS(SignedLiteralNode, NodeKind::SignedLiteral);

MAKE_NODE_TRAITS(UnsignedLiteralNode, NodeKind::UnsignedLiteral);

MAKE_NODE_TRAITS(CellLiteralNode, NodeKind::CellLiteral);

MAKE_NODE_TRAITS(InitializationNode, NodeKind::Initialization);

MAKE_NODE_TRAITS(IfNode, NodeKind::IfNode);

MAKE_NODE_TRAITS(WhileNode, NodeKind::WhileNode);

MAKE_NODE_TRAITS(FuncDeclNode, NodeKind::FuncDecl);

MAKE_NODE_TRAITS(FuncCallNode, NodeKind::FuncCall);

MAKE_NODE_TRAITS(XrayNode, NodeKind::XrayNode);

MAKE_NODE_TRAITS(PrintNode, NodeKind::PrintNode);

MAKE_NODE_TRAITS(RobotMoveNode, NodeKind::RobotMoveNode);

#endif //INTERPRETER_NODE_TRAITS_H
