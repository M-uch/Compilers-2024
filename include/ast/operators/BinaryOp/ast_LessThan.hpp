#ifndef AST_LESSTHAN_HPP
#define AST_LESSTHAN_HPP

#include "ast/ast_node.hpp"

class LessThan : public Node {
public:
    Node* left;
    Node* right;

    LessThan(Node* left, Node* right);
    virtual ~LessThan();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
