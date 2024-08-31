#ifndef INTERPRETER_MAP_H
#define INTERPRETER_MAP_H
#include "cell.h"
#include <vector>
#include "map_iterator.h"
#include "matrix_value.h"

class Map {
public:
    typedef MapIterator<true> const_iterator;

    typedef MapIterator<false> iterator;

    Map(size_t lines = 0, size_t columns = 0);

    size_t Columns() const noexcept;

    size_t Lines() const noexcept;

    iterator begin() noexcept;

    const_iterator begin() const noexcept;

    iterator end() noexcept;

    const_iterator end() const noexcept;

    iterator begin_from(size_t i, size_t j) noexcept;

    const_iterator begin_from(size_t i, size_t j) const noexcept;

    Map GetSurroundingArea(size_t i, size_t j, size_t new_lines, size_t new_columns) const noexcept;

    static MatrixValue MapToMatrix(const Map& map);

    static Map MatrixToMap(const MatrixValue& matrix);

private:
    friend class MapIterator<true>;

    friend class MapIterator<false>;

    std::vector<Cell> data_;

    size_t columns_;

    size_t lines_;
};

#endif //INTERPRETER_MAP_H
