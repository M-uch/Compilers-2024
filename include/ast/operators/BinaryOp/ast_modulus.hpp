#ifndef AST_MODULUS_HPP
#define AST_MODULUS_HPP

#include "ast/ast_node.hpp"

class Modulus : public Node {
public:
    Node* left;
    Node* right;

    Modulus(Node* left, Node* right);
    virtual ~Modulus();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
