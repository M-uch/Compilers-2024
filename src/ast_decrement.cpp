#include "ast/operators/UnaryOp/ast_decrement.hpp"
#include "ast/ast_identifier.hpp"

void Decrement::EmitRISC(std::ostream &stream, Context &context) const {

    // dynamic cast
    Identifier* id = dynamic_cast<Identifier*>(postfix_expression_);

    // find stack offset of variable
    int sOffset = context.getScopeSymTable().find(id->getID())->second.stackoffset_;

    // do increment
    std::string incReg = context.allocateRegister(stream);
    postfix_expression_->EmitRISC(stream, context, incReg);
    stream << "sub " << incReg << ", " << incReg  << ", 1" << std::endl;

    // store back in x
    stream << "sw " << incReg << ", " << context.getFrameSize() + sOffset << "(sp)" << std::endl;


}

void Decrement::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {
    // shouldn't do anything right?
}

void Decrement::Print(std::ostream &stream) const {
    postfix_expression_->Print(stream);
    stream << "--";
}
