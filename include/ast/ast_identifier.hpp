#ifndef AST_IDENTIFIER_HPP
#define AST_IDENTIFIER_HPP

#include "ast_node.hpp"

class Identifier : public Node
{
private:
    std::string identifier_;

public:
    Identifier(std::string identifier) : identifier_(identifier){};
    ~Identifier(){};
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
    std::string getID() const{
        return identifier_;
    }
};

#endif
