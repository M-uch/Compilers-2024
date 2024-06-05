#ifndef AST_NULL_HPP
#define AST_NULL_HPP

#include "ast_node.hpp"

class nullHandler : public Node
{
private:

public:
    nullHandler(){}
    ~nullHandler(){};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
