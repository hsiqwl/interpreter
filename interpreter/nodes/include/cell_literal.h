#ifndef INTERPRETER_CELL_LITERAL_H
#define INTERPRETER_CELL_LITERAL_H
#include "literal.h"
#include "cell_value.h"
#include "printable_interface.h"
#include <vector>

enum class WallPlaceholder {
    top,
    ntop,
    right,
    nright,
    down,
    ndown,
    left,
    nleft
};

class CellLiteralNode: public Literal, public IPrintable {
public:
    CellLiteralNode(std::vector<WallPlaceholder>&& init_list, const location_t& loc);

    Value GetValue() const noexcept override;

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

    static WallPlaceholder StringToWall(std::string_view string_repr);

    const std::vector<WallPlaceholder>& GetInitList() const;

private:
    std::vector<WallPlaceholder> init_list_;
};
#endif //INTERPRETER_CELL_LITERAL_H
