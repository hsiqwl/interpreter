#ifndef INTERPRETER_MATRIX_ELEM_REF_H
#define INTERPRETER_MATRIX_ELEM_REF_H
#include "var_ref.h"

class VarDeclNode;

class MatrixElementReferenceNode: public VarReferenceNode {
public:
    MatrixElementReferenceNode(std::string_view name,
                               std::unique_ptr<INode>&& horizontal_index,
                               std::unique_ptr<INode>&& vertical_index,
                               const location_t& loc);

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

    const INode& GetHorizontalIndex() const noexcept;

    const INode& GetVerticalIndex() const noexcept;

private:
    friend class VarDeclNode;

    std::shared_ptr<INode> horizontal_;

    std::shared_ptr<INode> vertical_;
};

#endif //INTERPRETER_MATRIX_ELEM_REF_H
