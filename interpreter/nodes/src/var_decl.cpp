#include "var_decl.h"
#include "node_visitor.h"

VarDeclNode::VarDeclNode(std::unique_ptr<VarReferenceNode> &&ref, const TypeHolder &type, const INode::location_t &loc,
                         bool is_const)
: INode(NodeKind::VarDecl, loc), const_(is_const), type_(type), name_(ref->GetVarName()) {
    auto p_ref = dynamic_cast<MatrixElementReferenceNode *>(&*ref);
    if (p_ref != nullptr) {
        horizontal_size_for_matrix_ = std::move(p_ref->horizontal_);
        vertical_size_for_matrix_ = std::move(p_ref->vertical_);
    }
    if (horizontal_size_for_matrix_ == nullptr)
        horizontal_size_for_matrix_ = std::make_shared<UnsignedLiteralNode>(4, loc);
    if (vertical_size_for_matrix_ == nullptr)
        vertical_size_for_matrix_ = std::make_shared<UnsignedLiteralNode>(4, loc);
}

void VarDeclNode::Accept(NodeVisitor &visitor) const {
    visitor.Visit(*this);
}

const std::string &VarDeclNode::GetName() const noexcept {
    return name_;
}

const TypeHolderWrapper & VarDeclNode::GetType() const noexcept {
    return type_;
}

bool VarDeclNode::IsConst() const noexcept {
    return const_;
}

void VarDeclNode::PrintOut(std::ostream &stream) const {
    stream << "VarDeclNode for variable '" << name_ << "' with type: " << type_.GetStringRepresentation() << '\n';
}

const INode &VarDeclNode::GetHorizontalSize() const {
    return *horizontal_size_for_matrix_;
}

const INode &VarDeclNode::GetVerticalSize() const {
    return *vertical_size_for_matrix_;
}