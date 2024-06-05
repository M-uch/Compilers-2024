#ifndef AST_MULTIPLICATION_HPP
#define AST_MULTIPLICATION_HPP

#include "ast/ast_node.hpp"

class Multiplication : public Node {
public:
    Node* left;
    Node* right;

    Multiplication(Node* left, Node* right);
    virtual ~Multiplication();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
