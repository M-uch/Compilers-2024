#ifndef AST_DEFAULT_HPP
#define AST_DEFAULT_HPP

#include "ast_node.hpp"

class defaultStatement : public Node
{
private:

    Node *statement_;

public:
    defaultStatement(Node *statement) : statement_(statement){}
    ~defaultStatement(){delete statement_;}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
