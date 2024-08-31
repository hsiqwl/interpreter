#ifndef INTERPRETER_PRINT_NODE_H
#define INTERPRETER_PRINT_NODE_H
#include "node_interface.h"
#include "printable_interface.h"

class PrintNode: public INode, public IPrintable {
public:
    PrintNode(std::unique_ptr<INode>&& expr, const location_t& loc);

    const INode& GetExprToPrint() const;

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream& stream) const override;

private:
    std::shared_ptr<INode> expr_to_print_;
};

#endif //INTERPRETER_PRINT_NODE_H
