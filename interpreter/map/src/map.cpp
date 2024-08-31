#include "map.h"

Map::Map(size_t lines, size_t columns): data_(lines * columns, Cell{true, true, true, true}),
columns_(columns), lines_(lines) {}

size_t Map::Columns() const noexcept {
    return columns_;
}

size_t Map::Lines() const noexcept {
    return lines_;
}

Map::iterator Map::begin() noexcept {
    return {data_.data()};
}

Map::const_iterator Map::begin() const noexcept {
    return {data_.data()};
}

Map::iterator Map::end() noexcept {
    return {&data_.back() + 1};
}

Map::const_iterator Map::end() const noexcept {
    return {&data_.back() + 1};
}

Map::iterator Map::begin_from(size_t i, size_t j) noexcept {
    return {data_.data() + i * columns_ + j};
}

Map::const_iterator Map::begin_from(size_t i, size_t j) const noexcept {
    return {data_.data() + i * columns_ + j};
}

Map Map::GetSurroundingArea(size_t i, size_t j, size_t new_lines, size_t new_columns) const noexcept {
    Map new_map(new_lines, new_columns);
    for(int row = 0; row < new_lines; ++row){
        for(int col = 0; col < new_columns; ++col){
            int this_row = i - new_lines/2 + row;
            int this_col = j - new_columns/2 + col;
            if(this_row >= 0 && this_row < lines_ && this_col >= 0 && this_col < columns_)
                *new_map.begin_from(row, col) = *begin_from(this_row, this_col);
        }
    }
    return new_map;
}

MatrixValue Map::MapToMatrix(const Map &map) {
    size_t max_horizontal_index = map.Columns() - 1;
    size_t max_vertical_index = map.Lines() - 1;
    TypeHolder type(TypeToken::Cell);
    type.MakeMatrixWrap();
    Value contained_value = CellValue{};
    MatrixValue matrix(max_horizontal_index, max_vertical_index, {type}, contained_value);
    size_t i = 0, j = 0;
    for(auto& map_cell: map) {
        matrix.GetElement(i, j)->SetValue({CellValue{map_cell}});
        if (!(j = (++j) % map.columns_))
            ++i;
    }
    return matrix;
}

Map Map::MatrixToMap(const MatrixValue &matrix) {
    size_t lines = matrix.Lines();
    size_t columns = matrix.Columns();
    Map map(lines, columns);
    auto iter = map.begin();
    for(size_t i = 0; i < lines; ++i){
        for(size_t j = 0; j < columns; ++j) {
            *iter = std::any_cast<Cell>(matrix.GetElement(i, j)->GetValue());
            ++iter;
        }
    }
    return map;
}