#ifndef INTERPRETER_CELL_H
#define INTERPRETER_CELL_H

enum class Direction{
    top,
    down,
    right,
    left
};

class Cell{
private:
    bool top_;

    bool down_;

    bool right_;

    bool left_;

public:
    Cell();

    Cell(bool top, bool down, bool right, bool left);

    explicit Cell(int wall_indicator);

    explicit Cell(unsigned wall_indicator);

    explicit operator int() const;

    explicit operator unsigned() const;

    [[nodiscard]] bool WallExists(Direction dir) const;

    Cell operator - (const Cell& other) const;

    Cell operator / (const Cell& other) const;

    Cell operator % (const Cell& other) const;
};

#endif //INTERPRETER_CELL_H
