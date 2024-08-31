#include "draw_commands.h"

DrawCommand::DrawCommand(const Map& map, const Robot &robot): map_(&map), robot_(&robot) {}

void DrawCommand::Run() {
    for (size_t i = 0; i < map_->Lines(); ++i) {
        for (size_t j = 0; j < map_->Columns(); ++j) {
            auto &cell = *map_->begin_from(i, j);
            std::cout << '#';
            if (cell.WallExists(Direction::top))
                std::cout << "#####";
            else
                std::cout << "     ";
            std::cout << '#';
        }
        std::cout << '\n';

        for (int k = 0; k < 1; ++k) {
            for (size_t j = 0; j < map_->Columns(); ++j) {
                auto &cell = *map_->begin_from(i, j);
                if (cell.WallExists(Direction::left))
                    std::cout << '#';
                else
                    std::cout << ' ';
                if(robot_->GetLocation().x == i && robot_->GetLocation().y == j)
                    std::cout << " ~~~ ";
                else
                    std::cout << "     ";
                if (cell.WallExists(Direction::right))
                    std::cout << '#';
                else
                    std::cout << ' ';
            }
            std::cout << '\n';
        }
        for (size_t j = 0; j < map_->Columns(); ++j) {
            auto &cell = *map_->begin_from(i, j);
            std::cout << '#';
            if (cell.WallExists(Direction::down))
                std::cout << "#####";
            else
                std::cout << "     ";
            std::cout << '#';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool DrawCommand::HasAccumulatedValue() const noexcept {
    return false;
}

std::any DrawCommand::GetAccumulatedValue() const {
    throw std::runtime_error("Cant get accumulated value after drawing");
}