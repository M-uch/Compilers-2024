#ifndef AST_DIVISION_HPP
#define AST_DIVISION_HPP

#include "ast/ast_node.hpp"

class Division : public Node {
public:
    Node* left;
    Node* right;

    Division(Node* left, Node* right);
    virtual ~Division();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
