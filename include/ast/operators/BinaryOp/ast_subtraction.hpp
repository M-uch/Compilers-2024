#ifndef AST_SUBTRACTION_HPP
#define AST_SUBTRACTION_HPP

#include "ast/ast_node.hpp"

class Subtraction : public Node {
public:
    Node* left;
    Node* right;

    Subtraction(Node* left, Node* right);
    virtual ~Subtraction();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
