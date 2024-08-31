#include "func_decl.h"
#include "node_visitor.h"

FuncDeclNode::FuncDeclNode(std::string_view func_name, std::unique_ptr<StatementListNode> &&body,
                           std::vector<std::unique_ptr<VarDeclNode>> &&params, const location_t &loc)
                   : INode(NodeKind::FuncDecl, loc), func_name_(func_name), body_(std::move(body)) {
    for (auto &param: params) {
        params_.emplace_back(std::move(param));
    }
}

const StatementListNode &FuncDeclNode::GetFuncBody() const noexcept {
    return *body_;
}

const std::vector<std::shared_ptr<VarDeclNode>> &FuncDeclNode::GetFuncParams() const noexcept {
    return params_;
}

const std::string &FuncDeclNode::GetFuncName() const noexcept {
    return func_name_;
}

void FuncDeclNode::Accept(NodeVisitor &visitor) const {
    visitor.Visit(*this);
}

void FuncDeclNode::PrintOut(std::ostream &stream) const {
    stream << "function declaration with '" << func_name_ << "' name\n";
}
