#include "cell_literal.h"
#include "node_visitor.h"

CellLiteralNode::CellLiteralNode(std::vector<WallPlaceholder> &&init_list, const INode::location_t &loc)
    : Literal(NodeKind::CellLiteral, loc), init_list_(std::move(init_list)) {}

void CellLiteralNode::Accept(NodeVisitor &visitor) const {
    visitor.Visit(*this);
}

void CellLiteralNode::PrintOut(std::ostream &stream) const {
    stream << "CellLiteralNode\n";
}

Value CellLiteralNode::GetValue() const noexcept {
    bool wall_top = false, wall_bottom = false, wall_right = false, wall_left = false;
    for (auto wall: init_list_) {
        switch (wall) {
            case WallPlaceholder::top: {
                wall_top = true;
                break;
            }
            case WallPlaceholder::ntop: {
                wall_top = false;
                break;
            }
            case WallPlaceholder::right: {
                wall_right = true;
                break;
            }
            case WallPlaceholder::nright: {
                wall_right = false;
                break;
            }
            case WallPlaceholder::down: {
                wall_bottom = true;
                break;
            }
            case WallPlaceholder::ndown: {
                wall_bottom = false;
                break;
            }
            case WallPlaceholder::left: {
                wall_left = true;
                break;
            }
            case WallPlaceholder::nleft: {
                wall_left = false;
                break;
            }
        }
    }
    return CellValue({wall_top, wall_bottom, wall_right, wall_left});
}

const std::vector<WallPlaceholder>& CellLiteralNode::GetInitList() const {
    return init_list_;
}

WallPlaceholder CellLiteralNode::StringToWall(std::string_view string_repr) {
    if (string_repr == "top")
        return WallPlaceholder::top;
    if (string_repr == "ntop")
        return WallPlaceholder::ntop;
    if (string_repr == "down")
        return WallPlaceholder::down;
    if (string_repr == "ndown")
        return WallPlaceholder::ndown;
    if (string_repr == "right")
        return WallPlaceholder::right;
    if (string_repr == "nright")
        return WallPlaceholder::nright;
    if (string_repr == "left")
        return WallPlaceholder::left;
    if (string_repr == "nleft")
        return WallPlaceholder::nleft;
}