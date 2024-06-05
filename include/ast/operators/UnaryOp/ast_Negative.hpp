#ifndef AST_NEGATIVE_HPP
#define AST_NEGATIVE_HPP

#include "ast/ast_node.hpp"

class Negative : public Node
{
private:
    Node *unary_expression_;

public:
    Negative(Node *unary_expression) : unary_expression_(unary_expression) {}
    ~Negative() {delete unary_expression_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;

};

#endif
