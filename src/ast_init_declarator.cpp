#include "ast/ast_init_declarator.hpp"

// do int x = a value;
void initDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{

    std::cout << "IN INITDEC" << std::endl;

    if (initialiser_ != nullptr) {
        std::string destReg = context.allocateRegister(stream);
        initialiser_->EmitRISC(stream, context, destReg);
        int varSOffset = context.getScopeSymTable().find(context.getVarID())->second.stackoffset_;
        stream << "sw " << destReg << ", " << context.getFrameSize() + varSOffset << "(sp)" << std::endl;
    } else {
        std::cout << "intialiser is null in ast_init_declarator.cpp" << std::endl;
    }

}

void initDeclarator::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const{}

void initDeclarator::Print(std::ostream &stream) const
{
    if(initialiser_ != nullptr) {
        initialiser_->Print(stream);
    }
}
