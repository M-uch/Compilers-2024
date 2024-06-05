#ifndef AST_BREAK_HPP
#define AST_BREAK_HPP

#include "ast_node.hpp"

class Break : public Node
{
private:

public:
    Break(){}

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
};

#endif
