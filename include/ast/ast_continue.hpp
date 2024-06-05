#ifndef AST_CONTINUE_HPP
#define AST_CONTINUE_HPP

#include "ast_node.hpp"

class Continue : public Node
{
private:

public:
    Continue(){}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
