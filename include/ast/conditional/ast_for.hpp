#ifndef AST_FOR_HPP
#define AST_FOR_HPP

#include "ast/ast_node.hpp"

class forLoop : public Node
{
private:
    Node *expression_statement1_;
    Node *expression_statement2_;
    Node *expression_;
    Node *statement_;

public:
    forLoop(Node *expression_statement1, Node* expression_statement2, Node* expression,  Node *statement) : expression_statement1_(expression_statement1), expression_statement2_(expression_statement2), expression_(expression), statement_(statement) {}
    ~forLoop() {delete expression_statement1_; delete expression_statement2_; delete statement_; if (expression_ != nullptr) {delete expression_;}};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;

};

#endif
