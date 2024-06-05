#ifndef AST_LOGICALNOT_HPP
#define AST_LOGICALNOT_HPP

#include "ast/ast_node.hpp"

class LogicalNOT : public Node
{
private:
    Node *unary_expression_;

public:
    LogicalNOT(Node *unary_expression) : unary_expression_(unary_expression) {}
    ~LogicalNOT() {delete unary_expression_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;

};

#endif
