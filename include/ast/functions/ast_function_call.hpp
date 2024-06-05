#ifndef AST_FUNCTION_CALL_HPP
#define AST_FUNCTION_CALL_HPP

#include "ast/ast_node.hpp"

class funcCall : public Node
{
private:
    Node *postfix_expression_;
    NodeList *argument_expression_list_;

public:
    // Constructor
    funcCall(Node *postfix_expression, NodeList *argument_expression_list) : postfix_expression_(postfix_expression), argument_expression_list_(argument_expression_list){};

    // Destructor
    ~funcCall(){ delete postfix_expression_; delete argument_expression_list_; };

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
