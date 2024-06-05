#include "ast/ast_assignment_expression.hpp"
#include "ast/ast_array_indexing.hpp"
#include "ast/ast_identifier.hpp"

void assignmentExpression::EmitRISC(std::ostream &stream, Context &context) const {


    std::cout << "IN ASSIGNMENT EXPRESSION" << std::endl;
    // For now lets assume that we are just doing x = value

    // dynamic casts
    Identifier* id = dynamic_cast<Identifier*>(getUnaryExp());
    arrayIndexing *aindex = dynamic_cast<arrayIndexing*>(getUnaryExp());

    if(aindex == nullptr) {

        std::cout << "ASSIGNING TO VARIABLE" << std::endl;
        // update to tell us what ID to assign to later in memory
        std::string varID = id->getID(); // e.g z or x etc
        context.updateVarID(id->getID());               // might not need to do the next lines
        std::cout << "varID is now: " << id->getID() << std::endl;

        // allocate destination register
        int tempIndex = context.allocateTemp(stream);
        std::string destReg = "t" + std::to_string(tempIndex);
        std::cout << "destReg for assignment is " << destReg << std::endl;

        // continue through parser
        Node *assignment_expression = getAssignExp();
        // assignment_expression->EmitRISC(stream, context);
        assignment_expression->EmitRISC(stream, context, destReg);

        // assign variable new value in memory
        Variable assignVar = context.getScopeSymTable().find(varID)->second;
        int assignSOffset = assignVar.stackoffset_;
        stream << "sw " << destReg << ", " << context.getFrameSize() + assignSOffset << "(sp)" << std::endl;

        // deallocate destReg
        context.deallocateTemp(tempIndex);
    } else {    // doing array indexing

        std::cout << "ASSIGNING TO ARRAY LOCATION" << std::endl;
        std::string arrayLoc = context.allocateRegister(stream);

        // get the memory location of array item
        aindex->EmitRISC(stream, context, arrayLoc);

        // get value to put in array
        std::string valReg = context.allocateRegister(stream);
        assignment_expression_->EmitRISC(stream, context, valReg);

        // store in memory
        stream << "sw " << valReg << ", " << 0 << "(" << arrayLoc << ")" << std::endl;

        context.deallocateRegister(valReg);
        context.deallocateRegister(arrayLoc);
    }

}

void assignmentExpression::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN ASSIGNMENT EXPRESSION /W DESTREG" << std::endl;
    // For now lets assume that we are just doing x = value

    // dynamic casts
    // Identifier* id = dynamic_cast<Identifier*>(getUnaryExp());

    // // update to tell us what ID to assign to later in memory
    // context.updateVarID(id->getID());
    // std::cout << "varID is now: " << id->getID() << std::endl;

    // // continue through parser
    // Node *assignment_expression = getAssignExp();
    // assignment_expression->EmitRISC(stream, context, destReg);
}

void assignmentExpression::Print(std::ostream &stream) const{
    
}




