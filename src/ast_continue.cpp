#include "ast/ast_continue.hpp"

void Continue::EmitRISC(std::ostream &stream, Context &context) const {

    std::string lNum = context.getItLabNum();

    // if it's a while loop
    if(context.getWhileFlag()) {
        stream << "beq, zero, zero, WHILE" << lNum << std::endl;
    } else if (context.getForFlag()) { // if for loop
        stream << "beq, zero, zero, FOR2" << lNum << std::endl;
    }
}
void Continue::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::string lNum = context.getItLabNum();

    // if it's a while loop
    if(context.getWhileFlag()) {
        stream << "beq, zero, zero, WHILE" << lNum << std::endl;
    } else if (context.getForFlag()) { // if for loop
        stream << "beq, zero, zero, FOR2" << lNum << std::endl;
    }
}
void Continue::Print(std::ostream &stream) const {

    stream << "continue;" << std::endl;
}
