#include "func_call.h"
#include "node_visitor.h"

FuncCallNode::FuncCallNode(std::string_view func_name, std::vector<std::unique_ptr<INode>> &&args,
                           const location_t &loc)
    : INode(NodeKind::FuncCall, loc), func_name_(func_name) {
    for (auto &arg: args) {
        args_.emplace_back(std::move(arg));
    }
}

const std::string &FuncCallNode::GetFuncName() const noexcept {
    return func_name_;
}

const std::vector<std::shared_ptr<INode>>& FuncCallNode::GetArgs() const noexcept {
    return args_;
}

void FuncCallNode::PrintOut(std::ostream &stream) const {
    stream << "calling '" << func_name_ << "' named func\n";
}

void FuncCallNode::Accept(NodeVisitor &visitor) const {
    visitor.Visit(*this);
}