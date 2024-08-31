#include "matrix_elem_ref.h"
#include "node_visitor.h"

MatrixElementReferenceNode::MatrixElementReferenceNode(std::string_view name, std::unique_ptr<INode> &&horizontal_index,
                                                       std::unique_ptr<INode> &&vertical_index,
                                                       const INode::location_t &loc)
                                                       : VarReferenceNode(name, loc),
                                                       horizontal_(std::move(horizontal_index)),
                                                       vertical_(std::move(vertical_index)) {}

void MatrixElementReferenceNode::Accept(NodeVisitor &visitor) const {
    visitor.Visit(*this);
}

void MatrixElementReferenceNode::PrintOut(std::ostream &stream) const {
    stream << "referencing matrix with name " << GetVarName() << " by indexes:\n";
    dynamic_cast<const IPrintable &>(*horizontal_).PrintOut(stream);
    dynamic_cast<const IPrintable &>(*vertical_).PrintOut(stream);
}

const INode &MatrixElementReferenceNode::GetVerticalIndex() const noexcept {
    return *vertical_;
}

const INode &MatrixElementReferenceNode::GetHorizontalIndex() const noexcept {
    return *horizontal_;
}