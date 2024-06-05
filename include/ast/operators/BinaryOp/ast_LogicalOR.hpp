#ifndef AST_LOGICALOR_HPP
#define AST_LOGICALOR_HPP

#include "ast/ast_node.hpp"

class LogicalOR : public Node {
public:
    Node* left;
    Node* right;

    LogicalOR(Node* left, Node* right);
    virtual ~LogicalOR();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
