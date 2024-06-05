#ifndef AST_GREATERTHANEQ_HPP
#define AST_GREATERTHANEQ_HPP

#include "ast/ast_node.hpp"

class GreaterThanEQ : public Node {
public:
    Node* left;
    Node* right;

    GreaterThanEQ(Node* left, Node* right);
    virtual ~GreaterThanEQ();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
