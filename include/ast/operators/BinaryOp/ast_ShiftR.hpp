#ifndef AST_SHIFTR_HPP
#define AST_SHIFTR_HPP

#include "ast/ast_node.hpp"

class RShift : public Node {
public:
    Node* left;
    Node* right;

    RShift(Node* left, Node* right);
    virtual ~RShift();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
