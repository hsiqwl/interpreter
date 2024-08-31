#include "map_commands.h"

MapVisionCommand::MapVisionCommand(const Map& receiver, const Robot& robot)
: receiver_(&receiver), line_number_(robot.GetLocation().x), column_number_(robot.GetLocation().y), accumulated_value_() {}

void MapVisionCommand::Run() {
    accumulated_value_ = receiver_->GetSurroundingArea(line_number_, column_number_, 5, 5);
}

bool MapVisionCommand::HasAccumulatedValue() const noexcept {
    return true;
}

std::any MapVisionCommand::GetAccumulatedValue() const {
    return std::make_any<MatrixValue>(Map::MapToMatrix(accumulated_value_));
}