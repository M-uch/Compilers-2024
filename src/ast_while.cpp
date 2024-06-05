#include "ast/conditional/ast_while.hpp"

void whileLoop::EmitRISC(std::ostream &stream, Context &context) const{

    // enter scope for while
    context.enterScope();

    std::string lNum = context.getItLabNum();
    context.whileTrue();

    std::string whileReg = context.allocateRegister(stream);
    stream << "WHILE" << lNum << ":" << std::endl;
    expression_->EmitRISC(stream, context, whileReg);
    stream << "beq " << whileReg << ", zero, ENDWHILE" << lNum << std::endl;
    statement_->EmitRISC(stream, context);
    stream << "beq zero, zero, WHILE" << lNum << std::endl;
    stream << "ENDWHILE" << lNum << ":" << std::endl;
    context.deallocateRegister(whileReg);

    context.updateItLab();
    context.whileFalse();
    context.exitScope();
}

void whileLoop::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const{

    // enter scope for while
    context.enterScope();

    std::string lNum = context.getItLabNum();
    context.whileTrue();

    std::string whileReg = context.allocateRegister(stream);
    stream << "WHILE" << lNum << ":" << std::endl;
    expression_->EmitRISC(stream, context, whileReg);
    stream << "beq " << whileReg << ", zero, ENDWHILE" << lNum << std::endl;
    statement_->EmitRISC(stream, context, destReg);
    stream << "beq zero, zero, WHILE" << lNum << std::endl;
    stream << "ENDWHILE" << lNum << ":" << std::endl;
    context.deallocateRegister(whileReg);

    context.updateItLab();
    context.whileFalse();
    context.exitScope();
}

void whileLoop::Print(std::ostream &stream) const{

    stream << "while (";
    expression_->Print(stream);
    stream << ") {" << std::endl;
    statement_->Print(stream);
    stream << std::endl;
    stream << "}" << std::endl;
}
