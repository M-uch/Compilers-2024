#ifndef AST_WHILE_HPP
#define AST_WHILE_HPP

#include "ast/ast_node.hpp"

class whileLoop : public Node
{
private:
    Node *expression_;
    Node *statement_;

public:
    whileLoop(Node *expression, Node *statement) : expression_(expression), statement_(statement) {}
    ~whileLoop() {delete expression_; delete statement_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;

};

#endif
