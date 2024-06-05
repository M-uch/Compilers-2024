#include "ast/conditional/ast_for.hpp"

void forLoop::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "ENTER FOR LOOP" << std::endl;
    std::cout << "Scope stack has size " << context.getScopeStack().size() << " before for loop" << std::endl;

    // create new scope for for loops
    context.enterScope();

    std::string lNum = context.getItLabNum();
    context.forTrue();

    // do the first part of the the loop e.g x=0;
    expression_statement1_->EmitRISC(stream, context);
    stream << "beq zero, zero, FOR1" << lNum << std::endl;

    // stuff inside for loop
    stream << "FOR2" << lNum << ":" << std::endl;
    statement_->EmitRISC(stream, context);
    if (expression_ != nullptr) // e.g i++
    {
        expression_->EmitRISC(stream, context);
    }

    // break condition evaluation
    stream << "FOR1" << lNum << ":" << std::endl;
    std::string forReg = context.allocateRegister(stream);
    expression_statement2_->EmitRISC(stream, context, forReg);
    stream << "bne " << forReg << ", zero, FOR2" << lNum << std::endl;
    stream << "ENDFOR" << lNum << ":" << std::endl;
    context.deallocateRegister(forReg);

    context.updateItLab();
    context.forFalse();
    context.exitScope();
}

void forLoop::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    // create new scope for for loops
    context.enterScope();

    std::string lNum = context.getItLabNum();
    context.forTrue();

    // do the first part of the the loop e.g x=0;
    expression_statement1_->EmitRISC(stream, context);
    stream << "beq zero, zero, FOR1" << lNum << std::endl;

    // stuff inside for loop
    stream << "FOR2" << lNum << ":" << std::endl;
    statement_->EmitRISC(stream, context, destReg);
    if (expression_ != nullptr) // e.g i++
    {
        expression_->EmitRISC(stream, context);
    }

    // break condition evaluation
    stream << "FOR1" << lNum << ":" << std::endl;
    std::string forReg = context.allocateRegister(stream);
    expression_statement2_->EmitRISC(stream, context, forReg);
    stream << "bne " << forReg << ", zero, FOR2" << lNum << std::endl;
    context.deallocateRegister(forReg);

    context.updateItLab();
    context.forFalse();
    context.exitScope();

    std::cout << "EXIT FOR LOOP" << std::endl;
}

void forLoop::Print(std::ostream &stream) const {
    stream << "for (";
    expression_statement1_->Print(stream);
    stream << "; ";
    expression_statement2_->Print(stream);
    stream << "; ";
    if (expression_ != nullptr) {
        expression_->Print(stream);
    }
    stream << ") {" << std::endl;
    statement_->Print(stream);
    stream << std::endl;
    stream << "}" << std::endl;
}
