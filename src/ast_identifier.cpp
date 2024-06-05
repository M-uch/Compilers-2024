#include "ast/ast_identifier.hpp"

void Identifier::EmitRISC(std::ostream &stream, Context &context) const
{
    // NEED TO CHANGE AND FIND IDENTIFIER IN FUNCTIONSTACK
    // lw a0 (wherever identifier is in memory - get from function stack)
    std::cout << "IN IDENTIFIER" << std::endl;
    stream << identifier_;
}

void Identifier::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN IDENTIFIER /W DESTREG" << std::endl;

    // store value from memory into destination register
    Variable loadVar = context.getScopeSymTable().find(identifier_)->second;
    int loadSOffset = loadVar.stackoffset_;
    stream << "lw " << destReg << ", " << context.getFrameSize() + loadSOffset <<  "(sp)" << std::endl;

}

void Identifier::Print(std::ostream &stream) const
{
    stream << identifier_;
};
