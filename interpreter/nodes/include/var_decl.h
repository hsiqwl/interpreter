#ifndef INTERPRETER_VAR_DECL_H
#define INTERPRETER_VAR_DECL_H
#include "node_interface.h"
#include "type_holder.h"
#include "printable_interface.h"
#include <optional>
#include "unsigned_literal.h"
#include "matrix_elem_ref.h"

class VarDeclNode: public INode, public IPrintable{
public:
    VarDeclNode(std::unique_ptr<VarReferenceNode>&& ref, const TypeHolder &type, const location_t &loc, bool is_const = false);

    [[nodiscard]] const std::string& GetName() const noexcept;

    [[nodiscard]] const TypeHolderWrapper & GetType() const  noexcept;

    [[nodiscard]] bool IsConst() const noexcept;

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

    const INode& GetHorizontalSize() const;

    const INode& GetVerticalSize() const;

private:
    std::string name_;

    TypeHolderWrapper type_;

    bool const_;

    std::shared_ptr<INode> horizontal_size_for_matrix_ = nullptr;

    std::shared_ptr<INode> vertical_size_for_matrix_ = nullptr;
};

#endif //INTERPRETER_VAR_DECL_H
