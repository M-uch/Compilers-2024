#ifndef AST_CASE_STATEMENT_HPP
#define AST_CASE_STATEMENT_HPP

#include "ast_node.hpp"

class caseStatement : public Node
{
private:

    Node *constant_expression_;
    Node *statement_;

public:
    caseStatement(Node *constant_expression, Node *statement) : constant_expression_(constant_expression), statement_(statement){}
    ~caseStatement(){delete constant_expression_; delete statement_;}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
    Node *getConstExp() const {
        return constant_expression_;
    }
    Node *getStatement() const {
        return statement_;
    }
};

#endif
