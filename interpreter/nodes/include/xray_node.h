#ifndef INTERPRETER_XRAY_NODE_H
#define INTERPRETER_XRAY_NODE_H
#include "node_interface.h"
#include "printable_interface.h"

class XrayNode: public INode, public IPrintable {
public:
    XrayNode(const location_t& loc);

    void Accept(NodeVisitor& visitor) const override;

    void PrintOut(std::ostream & stream) const override;
};

#endif //INTERPRETER_XRAY_NODE_H
