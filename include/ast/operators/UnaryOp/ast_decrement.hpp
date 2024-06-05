#ifndef AST_DECREMENT_HPP
#define AST_DECREMENT_HPP

#include "ast/ast_node.hpp"

class Decrement : public Node
{
private:
    Node *postfix_expression_;

public:
    Decrement(Node *postfix_expression) : postfix_expression_(postfix_expression) {}
    ~Decrement() {delete postfix_expression_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;

};

#endif
