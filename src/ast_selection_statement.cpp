#include "ast/conditional/ast_selection_statement.hpp"

void selectionStatement::EmitRISC(std::ostream &stream, Context &context) const{

    std::cout << "IN SELECTION STATEMENT" << std::endl;

    // enter scope for if statement
    context.enterScope();

    // get if expression
    std::string ifReg = context.allocateRegister(stream);
    std::cout << "ifReg = " << ifReg << std::endl;
    ifExp_->EmitRISC(stream, context, ifReg);

    std::string lNum = context.getIfLabNum();

    // If we are doing if-else
    if (elseState_ != nullptr) {
        stream << "beq " << ifReg << ", zero, ELSE" << lNum << std::endl;
        ifState_->EmitRISC(stream, context);
        stream << "bne " << ifReg << ", zero, ENDIF" << lNum << std::endl;
        context.deallocateRegister(ifReg);
        stream << "ELSE" << lNum << ":" << std::endl;
        elseState_->EmitRISC(stream, context);
        stream << "ENDIF" << lNum << ":" << std::endl;

    } else { // just an if
        stream << "beq " << ifReg << ", zero, ENDIF" << lNum << std::endl;
        context.deallocateRegister(ifReg);
        ifState_->EmitRISC(stream, context);
        stream << "ENDIF" << lNum << ":" << std::endl;
    }

    context.updateIfLab();
    context.exitScope();
}

void selectionStatement::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const{

    // NOT SURE WHAT TO PUT HERE YET (IF ANYTHING)
    std::cout << "IN SELECTION STATEMENT W/ DESTREG" << std::endl;

    // enter scope for if statement
    context.enterScope();

    // get if expression
    std::string ifReg = context.allocateRegister(stream);
    std::cout << "ifReg = " << ifReg << std::endl;
    ifExp_->EmitRISC(stream, context, ifReg);

    std::string lNum = context.getIfLabNum();

    // If we are doing if-else
    if (elseState_ != nullptr) {
        stream << "beq " << ifReg << ", zero, ELSE" << lNum << std::endl;
        ifState_->EmitRISC(stream, context, destReg);
        stream << "bne " << ifReg << ", zero, ENDIF" << lNum << std::endl;
        context.deallocateRegister(ifReg);
        stream << "ELSE" << lNum << ":" << std::endl;
        elseState_->EmitRISC(stream, context, destReg);
        stream << "ENDIF" << lNum << ":" << std::endl;

    } else { // just an if
        stream << "beq " << ifReg << ", zero, ENDIF" << lNum << std::endl;
        context.deallocateRegister(ifReg);
        ifState_->EmitRISC(stream, context, destReg);
        stream << "ENDIF" << lNum << ":" << std::endl;
    }

    context.updateIfLab();
    context.exitScope();
}

void selectionStatement::Print(std::ostream &stream) const {

    stream << "if (" << std::endl;
    ifExp_->Print(stream);
    stream << ") {" << std::endl;
    // If we are doing if-else
    if (elseState_ != nullptr) {

        ifState_->Print(stream);
        stream << "} else {" << std::endl;
        elseState_->Print(stream);

    } else { // just an if

        ifState_->Print(stream);
    }

    stream << "}" << std::endl;
}
