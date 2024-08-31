#include "cell.h"

Cell::Cell(bool top, bool down, bool right, bool left) {
    top_ = top;
    down_ = down;
    right_ = right;
    left_ = left;
}

Cell::Cell(): Cell(false, false, false, false) {}

Cell::Cell(int wall_indicator) {
    if (wall_indicator)
        top_ = down_ = right_ = left_ = true;
    else
        top_ = down_ = right_ = left_ = false;
}

Cell::Cell(unsigned wall_indicator) {
    if (wall_indicator)
        top_ = down_ = right_ = left_ = true;
    else
        top_ = down_ = right_ = left_ = false;
}

bool Cell::WallExists(Direction dir) const {
    switch (dir) {
        case Direction::top:
            return top_;
        case Direction::down:
            return down_;
        case Direction::right:
            return right_;
        case Direction::left:
            return left_;
    }
}

Cell Cell::operator-(const Cell &other) const {
    bool new_top = top_ ^ other.top_;
    bool new_down = down_ ^ other.down_;
    bool new_right = right_ ^ other.right_;
    bool new_left = left_ ^ other.left_;
    return {new_top, new_down, new_right, new_left};
}

Cell Cell::operator/(const Cell &other) const {
    bool new_top = top_ | other.top_;
    bool new_down = down_ | other.down_;
    bool new_right = right_ | other.right_;
    bool new_left = left_ | other.left_;
    return {new_top, new_down, new_right, new_left};
}

Cell Cell::operator%(const Cell &other) const {
    bool new_top = top_ & other.top_;
    bool new_down = down_ & other.down_;
    bool new_right = right_ & other.right_;
    bool new_left = left_ & other.left_;
    return {new_top, new_down, new_right, new_left};
}

Cell::operator int() const {
    if (top_ || down_ || left_ || right_)
        return 1;
    return 0;
}

Cell::operator unsigned() const {
    if (top_ || down_ || left_ || right_)
        return 1;
    return 0;
}
