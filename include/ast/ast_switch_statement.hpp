#ifndef AST_SWITCH_STATEMENT_HPP
#define AST_SWITCH_STATEMENT_HPP

#include "ast_node.hpp"

class switchStatement : public Node
{
private:

    Node *expression_;
    Node *statement_;

public:
    switchStatement(Node *expression, Node *statement) : expression_(expression), statement_(statement){}
    ~switchStatement(){delete expression_; delete statement_;}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
