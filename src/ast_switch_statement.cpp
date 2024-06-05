#include "ast/ast_switch_statement.hpp"
#include "ast/ast_compound_statement.hpp"


void switchStatement::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN SWITCH STATEMENT" << std::endl;

    context.switchTrue();

    // dynamic casts
    compoundStatement *cs = dynamic_cast<compoundStatement*>(statement_);

    // get value that holds switch condition
    std::string swReg = context.allocateRegister(stream);
    expression_->EmitRISC(stream, context, swReg);

    if (cs != nullptr) {
        cs->EmitRISC(stream, context, swReg);
    } else {
        std::cout << "SWITCH STATEMENT IS NOT A COMPOUND STATEMENT???" << std::endl;
    }

    stream << "ENDSWITCH" << context.getSwLabNum() << ":" << std::endl;

    context.updateSwLab();
    context.deallocateRegister(swReg);
    context.switchFalse();
    // context.exitScope();
}

void switchStatement::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {}

void switchStatement::Print(std::ostream &stream) const {}
