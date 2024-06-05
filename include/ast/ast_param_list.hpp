#ifndef AST_PARAM_LIST_HPP
#define AST_PARAM_LIST_HPP

#include "ast_node.hpp"

class ParamList : public NodeList {

    private:

    public:

    ParamList(Node *parameter) : NodeList(parameter) {};
    virtual ~ParamList(){};

    virtual void EmitRISC(std::ostream &stream, Context &context) const override;
};

#endif
