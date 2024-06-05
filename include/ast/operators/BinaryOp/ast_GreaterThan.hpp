#ifndef AST_GREATERTHAN_HPP
#define AST_GREATERTHAN_HPP

#include "ast/ast_node.hpp"

class GreaterThan : public Node {
public:
    Node* left;
    Node* right;

    GreaterThan(Node* left, Node* right);
    virtual ~GreaterThan();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
