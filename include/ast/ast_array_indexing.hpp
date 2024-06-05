#ifndef AST_ARRAY_INDEXING_HPP
#define AST_ARRAY_INDEXING_HPP

#include "ast_node.hpp"

class arrayIndexing : public Node
{
private:
    Node *postfix_expression_;
    Node *expression_;

public:

    // Constructor
    arrayIndexing(Node *postfix_expression, Node *expression) : postfix_expression_(postfix_expression), expression_(expression){}; 

    // Destructor
    ~arrayIndexing() { delete postfix_expression_; delete expression_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;

    void Print(std::ostream &stream) const override;

};

#endif
