#ifndef AST_LOGICALAND_HPP
#define AST_LOGICALAND_HPP

#include "ast/ast_node.hpp"

class LogicalAND : public Node {
public:
    Node* left;
    Node* right;

    LogicalAND(Node* left, Node* right);
    virtual ~LogicalAND();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
