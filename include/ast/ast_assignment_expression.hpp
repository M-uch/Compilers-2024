#ifndef AST_ASSIGNMENT_EXPRESSION_HPP
#define AST_ASSIGNMENT_EXPRESSION_HPP

#include "ast_node.hpp"

class assignmentExpression : public Node
{
private:
    Node *unary_expression_;
    Node *assignment_expression_;

public:

    // Constructor
    assignmentExpression(Node *unary_expression, Node *assignment_expression) : unary_expression_(unary_expression), assignment_expression_(assignment_expression){}; // same here

    // Destructor
    ~assignmentExpression() { delete unary_expression_; delete assignment_expression_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;

    void Print(std::ostream &stream) const override;
    Node *getUnaryExp() const{

        return unary_expression_;
    }
    Node *getAssignExp() const{
        return assignment_expression_;
    }
};

#endif
