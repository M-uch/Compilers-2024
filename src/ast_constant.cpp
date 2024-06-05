#include "ast/ast_constant.hpp"

void IntConstant::EmitRISC(std::ostream &stream, Context &context) const
{
    std::cout << "IN INT CONSTANT" << std::endl;
    // if we are returning int constant
    if (context.getRetFlag()) {
        std::cout << "returnFlag is true" << std::endl;
        stream << "li a0, " << value_ << std::endl;
        stream << "beq zero, zero, " << context.makeLabel() << std::endl;
        context.retFalse();
    } else { // otherwise we are assigning
        std::cout << "returnFlag is false" << std::endl;
        std::string varID = context.getVarID();
        std::cout << "assigning " << value_ << " to " << varID << std::endl;

        // find variable stack location
        Variable assignVar = context.getScopeSymTable().find(varID)->second;
        int stackOffset = context.getFrameSize() + assignVar.stackoffset_;

        // find available temp reg
        int tempReg = context.allocateTemp(stream);

        stream << "li t" << tempReg << ", " << value_ << std::endl; // load the value in temp reg
        stream << "sw t" << tempReg << ", " << stackOffset << "(sp)" << std::endl;
        context.deallocateTemp(tempReg);
    }
}

void IntConstant::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {
    std::cout << "IN INT CONSTANT W/ DESTREG" << std::endl;
    stream << "li " << destReg << ", " << value_ << std::endl;
}

void IntConstant::Print(std::ostream &stream) const
{
    stream << value_;
}
