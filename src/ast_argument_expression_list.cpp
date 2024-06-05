#include "ast/ast_argument_expression_list.hpp"

void ArgList::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN ARGUMENT LIST" << std::endl;
    // iterate through all arguments and assign argument registers
    int i = 0;
    for (Node *arg : getNodes()) {
        std::string argReg = "a" + std::to_string(i);
        std::cout << "function call using " << argReg << std::endl;
        context.makeUsed(i+10); // NOTE THIS MIGHT CONFLICT WITH FUNCTION DEF!!!

        int tempIndex = context.allocateTemp(stream);
        std::cout << "tempIndex is " << tempIndex << std::endl;
        std::string destReg = "t" + std::to_string(tempIndex);

        arg->EmitRISC(stream, context, destReg);
        stream << "mv " << argReg << "," << destReg << std::endl;
        context.deallocateTemp(tempIndex);
        i++;
    }
}
