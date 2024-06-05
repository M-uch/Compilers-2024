#ifndef AST_ARGUMENT_EXPRESSION_LIST_HPP
#define AST_ARGUMENT_EXPRESSION_LIST_HPP

#include "ast_node.hpp"

class ArgList : public NodeList {

    private:

    public:

    ArgList(Node *argument_expression) : NodeList(argument_expression) {};
    virtual ~ArgList(){};

    virtual void EmitRISC(std::ostream &stream, Context &context) const override;

};

#endif
