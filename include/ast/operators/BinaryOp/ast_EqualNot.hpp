#ifndef AST_EQUALNOT_HPP
#define AST_EQUALNOT_HPP

#include "ast/ast_node.hpp"

class NotEqual : public Node {
public:
    Node* left;
    Node* right;

    NotEqual(Node* left, Node* right);
    virtual ~NotEqual();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
