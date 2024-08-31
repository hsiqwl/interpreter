#include "robot.h"

Robot::Robot(UnitLocation location): location_(location) {}

const UnitLocation &Robot::GetLocation() const {
    return location_;
}

void Robot::Move(MoveDirection direction) {
    switch (direction) {
        case MoveDirection::top: {
            location_.x -= 1;
            return;
        }
        case MoveDirection::bottom: {
            location_.x += 1;
            return;
        }
        case MoveDirection::right: {
            location_.y += 1;
            return;
        }
        case MoveDirection::left: {
            location_.y -= 1;
            return;
        }
    }
}