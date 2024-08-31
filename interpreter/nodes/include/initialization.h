#ifndef INTERPRETER_INITIALIZATION_H
#define INTERPRETER_INITIALIZATION_H
#include "node_interface.h"
#include "var_decl.h"
#include <any>
#include "printable_interface.h"

class InitializationNode: public INode, public IPrintable{
public:
    InitializationNode(std::unique_ptr<VarDeclNode> &&var_to_init, std::unique_ptr<INode> &&init_expr,
                       const location_t &loc);

    const INode& GetInitExpr() const noexcept;

    const VarDeclNode& GetVarToInit() const noexcept;

    bool InitExprIsEmpty() const noexcept;

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

private:
    std::shared_ptr<VarDeclNode> var_to_init_;

    std::shared_ptr<INode> init_expr_;
};

#endif //INTERPRETER_INITIALIZATION_H
