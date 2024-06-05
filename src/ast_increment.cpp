#include "ast/operators/UnaryOp/ast_increment.hpp"
#include "ast/ast_identifier.hpp"

void Increment::EmitRISC(std::ostream &stream, Context &context) const {

    // dynamic cast
    Identifier* id = dynamic_cast<Identifier*>(postfix_expression_);

    // find stack offset of variable
    int sOffset = context.getScopeSymTable().find(id->getID())->second.stackoffset_;

    // do increment
    std::string incReg = context.allocateRegister(stream);
    postfix_expression_->EmitRISC(stream, context, incReg);
    stream << "addi " << incReg << ", " << incReg  << ", 1" << std::endl;

    // store back in x
    stream << "sw " << incReg << ", " << context.getFrameSize() + sOffset << "(sp)" << std::endl;


}

void Increment::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {
    // shouldn't do anything right?
}

void Increment::Print(std::ostream &stream) const {
    postfix_expression_->Print(stream);
    stream << "++";
}
