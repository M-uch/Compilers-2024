#ifndef AST_INCREMENT_HPP
#define AST_INCREMENT_HPP

#include "ast/ast_node.hpp"

class Increment : public Node
{
private:
    Node *postfix_expression_;

public:
    Increment(Node *postfix_expression) : postfix_expression_(postfix_expression) {}
    ~Increment() {delete postfix_expression_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;

};

#endif
