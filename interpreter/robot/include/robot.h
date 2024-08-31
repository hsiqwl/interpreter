#ifndef INTERPRETER_ROBOT_H
#define INTERPRETER_ROBOT_H
#include <cstddef>

enum class MoveDirection {
    top,
    bottom,
    left,
    right
};

struct UnitLocation {
    size_t x = 0, y = 0;
};

class Robot {
public:
    Robot(UnitLocation location = UnitLocation{});

    void Move(MoveDirection direction);

    const UnitLocation& GetLocation() const;

private:
    UnitLocation location_;
};

#endif //INTERPRETER_ROBOT_H
