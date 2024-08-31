#include "matrix_value.h"

size_t MatrixValue::GetNumericValue(const IValue &value) {
    switch (value.GetType().GetSimpleType()) {
        case TypeToken::Signed: {
            return std::any_cast<int>(value.GetValue());
        }
        case TypeToken::Unsigned: {
            return static_cast<unsigned >(std::any_cast<unsigned>(value.GetValue()));
        }
        case TypeToken::Cell: {
            return static_cast<unsigned >(std::any_cast<Cell>(value.GetValue()));
        }
    }
}

Cell MatrixValue::GetCellValue(const IValue &value) {
    return std::any_cast<Cell>(value.GetValue());
}

MatrixValue::MatrixValue(size_t max_horizontal_index, size_t max_vertical_index,
                         const TypeHolderWrapper& type, Value &contained_value)
: IValue(type), ValueHolder<std::vector<std::vector<Value>>>({max_vertical_index + 1, {max_horizontal_index + 1, contained_value}}){}

MatrixValue::MatrixValue(Value max_horizontal_index, Value max_vertical_index,
                          Value& contained_value, const TypeHolderWrapper &type)
: IValue(type), ValueHolder<std::vector<std::vector<Value>>>() {
    size_t horizontal_size = GetNumericValue(*max_horizontal_index) + 1;
    size_t vertical_size = GetNumericValue(*max_vertical_index) + 1;
    value_ = matrix_t{vertical_size, {horizontal_size, contained_value}};
}

MatrixValue::MatrixValue(Value& contained_value, const TypeHolderWrapper &type)
    : MatrixValue(UnsignedValue(4), UnsignedValue(4), contained_value, type) {}

std::any MatrixValue::GetValue() const {
    return std::make_any<matrix_t>(value_);
}

void MatrixValue::SetValue(Value &&new_value) {
    value_ = std::any_cast<matrix_t>(new_value->GetValue());
}

Value MatrixValue::Equal(const IValue &other) const {
    throw std::logic_error("Cannot perform comparing operator '=' for matrix type");
}

Value MatrixValue::Greater(const IValue &other) const {
    throw std::logic_error("Cannot perform comparing operator '>' for matrix type");
}

Value MatrixValue::Less(const IValue &other) const {
    throw std::logic_error("Cannot perform comparing operator '<' for matrix type");
}

Value MatrixValue::UnaryMinus() const {
    MatrixValue new_matrix{*this};
    for (auto &line: new_matrix.value_) {
        for (auto &element: line) {
            element = element->UnaryMinus();
        }
    }
    return new_matrix;
}

Value MatrixValue::UnaryPlus() const {
    MatrixValue new_matrix{*this};
    for (auto &line: new_matrix.value_) {
        for (auto &element: line) {
            element = element->UnaryPlus();
        }
    }
    return new_matrix;
}

Value MatrixValue::Hash() const {
    MatrixValue new_matrix{*this};
    if (GetType().GetSimpleType() == TypeToken::Cell)
        HashForCellElements(new_matrix);
    else
        HashForNumericElements(new_matrix);
    return new_matrix;
}

Value MatrixValue::Percent(const IValue &other) const {
    auto &other_matrix = dynamic_cast<const MatrixValue &>(other);
    MatrixValue new_matrix = MakeIntersectionWith(other_matrix);
    for (size_t i = 0; i < new_matrix.value_.size(); ++i) {
        for (size_t j = 0; j < new_matrix.value_[0].size(); ++j) {
            new_matrix.value_[i][j] = new_matrix.value_[i][j]->Percent(*other_matrix.value_[i][j]);
        }
    }
    return new_matrix;
}

Value MatrixValue::Slash(const IValue &other) const {
    auto &other_matrix = dynamic_cast<const MatrixValue &>(other);
    MatrixValue new_matrix = MakeIntersectionWith(other_matrix);
    for (size_t i = 0; i < new_matrix.value_.size(); ++i) {
        for (size_t j = 0; j < new_matrix.value_[0].size(); ++j) {
            new_matrix.value_[i][j] = new_matrix.value_[i][j]->Slash(*other_matrix.value_[i][j]);
        }
    }
    return new_matrix;
}

Value MatrixValue::Star(const IValue &other) const {
    auto &other_matrix = dynamic_cast<const MatrixValue &>(other);
    MatrixValue new_matrix = MakeIntersectionWith(other_matrix);
    for (size_t i = 0; i < new_matrix.value_.size(); ++i) {
        for (size_t j = 0; j < new_matrix.value_[0].size(); ++j) {
            new_matrix.value_[i][j] = new_matrix.value_[i][j]->Star(*other_matrix.value_[i][j]);
        }
    }
    return new_matrix;
}

Value MatrixValue::Plus(const IValue &other) const {
    auto &other_matrix = dynamic_cast<const MatrixValue &>(other);
    MatrixValue new_matrix = MakeIntersectionWith(other_matrix);
    for (size_t i = 0; i < new_matrix.value_.size(); ++i) {
        for (size_t j = 0; j < new_matrix.value_[0].size(); ++j) {
            new_matrix.value_[i][j] = new_matrix.value_[i][j]->Plus(*other_matrix.value_[i][j]);
        }
    }
    return new_matrix;
}

Value MatrixValue::Minus(const IValue &other) const {
    auto &other_matrix = dynamic_cast<const MatrixValue &>(other);
    MatrixValue new_matrix = MakeIntersectionWith(other_matrix);
    for (size_t i = 0; i < new_matrix.value_.size(); ++i) {
        for (size_t j = 0; j < new_matrix.value_[0].size(); ++j) {
            new_matrix.value_[i][j] = new_matrix.value_[i][j]->Minus(*other_matrix.value_[i][j]);
        }
    }
    return new_matrix;
}

Value &MatrixValue::SubscriptOperator(const IValue &line, const IValue &column) {
    size_t i = GetNumericValue(line), j = GetNumericValue(column);
    return value_[i][j];
}

Value &MatrixValue::GetElement(size_t i, size_t j) {
    return value_[i][j];
}

const Value &MatrixValue::GetElement(size_t i, size_t j) const {
    return value_[i][j];
}

void MatrixValue::PrintOut(std::ostream &stream) const {
    stream << "matrix of type: " << GetType().GetStringRepresentation() << '\n';
    stream << "lines:" << value_.size() << ", columns:" << value_[0].size() << '\n';
    bool numeric = GetType().GetInnerType().IsSameAs(TypeHolderWrapper{TypeToken::Signed}) ||
                   GetType().GetInnerType().IsSameAs(TypeHolderWrapper{TypeToken::Unsigned});
    if (numeric)
        PrintOutForNumeric(stream);
    else
        PrintOutForNonNumeric(stream);
}

void MatrixValue::PrintOutForNonNumeric(std::ostream &stream) const {
    for (size_t i = 0; i < value_.size(); ++i) {
        for (size_t j = 0; j < value_[i].size(); ++j) {
            auto fmt_string = (boost::format("[%1%][%2%]: ") % i % j).str();
            stream << fmt_string;
            value_[i][j]->PrintOut(stream);
            stream << '\n';
        }
    }
}

void MatrixValue::PrintOutForNumeric(std::ostream &stream) const {
    for (auto &line: value_) {
        for (auto &elem: line) {
            elem->PrintOut(stream);
            stream << ' ';
        }
        stream << '\n';
    }
}

void MatrixValue::HashForNumericElements(MatrixValue &matrix) const {
    int sum_of_elements = 0;
    for (auto &line: matrix.value_) {
        for (auto &elem: line) {
            sum_of_elements += GetNumericValue(*elem);
        }
    }
    int average = sum_of_elements / value_.size() * (value_.begin()->size());
    for (auto &line: matrix.value_) {
        for (auto &elem: line) {
            elem->SetValue(SignedValue(average));
        }
    }
}

void MatrixValue::HashForCellElements(MatrixValue &matrix) const {
    matrix.ExpandCellMatrixTemporary();
    for (size_t i = 1; i < matrix.value_.size() - 1; ++i) {
        for (size_t j = 1; j < matrix.value_[0].size() - 1; ++j) {
            auto current_cell = GetCellValue(*matrix.value_[i][j]);
            bool bottom = current_cell.WallExists(Direction::down) |
                          GetCellValue(*matrix.value_[i + 1][j]).WallExists(Direction::top);
            bool top = current_cell.WallExists(Direction::top) |
                       GetCellValue(*matrix.value_[i - 1][j]).WallExists(Direction::down);
            bool left = current_cell.WallExists(Direction::left) |
                        GetCellValue(*matrix.value_[i][j - 1]).WallExists(Direction::right);
            bool right = current_cell.WallExists(Direction::right) |
                         GetCellValue(*matrix.value_[i][j + 1]).WallExists(Direction::left);
            matrix.value_[i][j]->SetValue(CellValue{Cell{top, bottom, right, left}});
        }
    }
    matrix.ShrinkCellMatrix();
}

void MatrixValue::ExpandCellMatrixTemporary() {
    value_.emplace(value_.begin(), value_[0].size(), CellValue{{true, true, true, true}});
    value_.emplace_back(value_[0].size(), CellValue{{true, true, true, true}});
    for (auto &line: value_) {
        line.emplace_back(CellValue{{true, true, true, true}});
        line.emplace(line.begin(), CellValue{{true, true, true, true}});
    }
}

void MatrixValue::ShrinkCellMatrix() {
    value_.erase(value_.begin());
    value_.pop_back();
    for(auto& line: value_) {
        line.pop_back();
        line.erase(line.begin());
    }
}

MatrixValue MatrixValue::MakeIntersectionWith(const MatrixValue &other) const {
    size_t intersection_horizontal = std::min(value_.size() - 1, other.value_.size() - 1);
    size_t intersection_vertical = std::min(value_[0].size() - 1, other.value_[0].size() - 1);
    Value contained_value = value_[0][0];
    MatrixValue new_matrix{intersection_horizontal, intersection_vertical, GetType(), contained_value};
    for (size_t i = 0; i <= intersection_horizontal; ++i) {
        for (size_t j = 0; j <= intersection_vertical; ++j) {
            new_matrix.value_[i][j] = value_[i][j];
        }
    }
    return new_matrix;
}

size_t MatrixValue::Lines() const noexcept {
    return value_.size();
}

size_t MatrixValue::Columns() const noexcept {
    return value_[0].size();
}