#include "ast/ast_break.hpp"

void Break::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN BREAK" << std::endl;

    std::string lNum = context.getItLabNum();
    std::string slNum = context.getSwLabNum();

    // if it's a while loop
    if(context.getWhileFlag()) {
        stream << "beq zero, zero, ENDWHILE" << lNum << std::endl;
    } else if (context.getForFlag()) { // if for loop
        stream << "beq zero, zero, ENDFOR" << lNum << std::endl;
    } else if (context.getSwitchFlag()) { // if switch
        stream << "beq zero, zero, ENDSWITCH" << slNum << std::endl;
    }
}
void Break::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN BREAK" << std::endl;

    std::string lNum = context.getItLabNum();
    std::string slNum = context.getSwLabNum();

    // if it's a while loop
    if(context.getWhileFlag()) {
        stream << "beq zero, zero, ENDWHILE" << lNum << std::endl;
    } else if (context.getForFlag()) { // if for loop
        stream << "beq zero, zero, ENDFOR" << lNum << std::endl;
    }  else if (context.getSwitchFlag()) { // if switch
        stream << "beq zero, zero, ENDSWITCH" << slNum << std::endl;
    }
}
void Break::Print(std::ostream &stream) const {

   stream << "break;" << std::endl;
}
