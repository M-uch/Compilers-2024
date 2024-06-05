#ifndef AST_BITWISENOT_HPP
#define AST_BITWISENOT_HPP

#include "ast/ast_node.hpp"

class BitwiseNOT : public Node
{
private:
    Node *unary_expression_;

public:
    BitwiseNOT(Node *unary_expression) : unary_expression_(unary_expression) {}
    ~BitwiseNOT() {delete unary_expression_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;

};

#endif
