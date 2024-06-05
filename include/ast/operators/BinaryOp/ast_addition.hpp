#ifndef AST_ADDITION_HPP
#define AST_ADDITION_HPP

#include "ast/ast_node.hpp"

class Addition : public Node {
public:
    Node* left;
    Node* right;

    Addition(Node* left, Node* right);
    virtual ~Addition();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
