#include "ast/ast_array_declarator.hpp"
#include "ast/ast_identifier.hpp"
#include "ast/ast_constant.hpp"

void arrayDeclarator::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN ARRAY DECLARATOR" << std::endl;

    // dynamic cast
    Identifier *id = dynamic_cast<Identifier*>(direct_declarator_);
    IntConstant *asize = dynamic_cast<IntConstant*>(constant_expression_);

    std::string arrayID = id->getID();
    int arraySize = asize->getVal();
    context.updateArrayID(arrayID);

    // now add array 'pointer' to stack (represents name 'x')
    if (context.getScopeStack().size() == 0) { // if global
        Function newScope;
        context.pushToStack(newScope);
    }
    int sOffset = context.getStackOffset(context.getScopeSymTable(), "int");
    Variable arrayPointer("int", -4, sOffset);
    context.addToSymbolTable(context.getScopeSymTable(), arrayID, arrayPointer);

    // now store array size at memory location
    std::string arrayReg = context.allocateRegister(stream);
    constant_expression_->EmitRISC(stream, context, arrayReg);
    stream << "sw " << arrayReg << ", " << context.getFrameSize() + sOffset << "(sp)" << std::endl;

    std::cout << "Storing array pointer at " << context.getFrameSize() + sOffset << "(sp) - with a size defined in " << arrayReg << std::endl;
    context.deallocateRegister(arrayReg);

    for (int i=0; i<arraySize; i++) {
        // store placeholder items in memory to 'allocate it'
        int aItemSOffset = context.getStackOffset(context.getScopeSymTable(), "int");
        Variable arrayItem("int", -4, aItemSOffset);
        std::string tempName = "arrayItem" + std::to_string(i);

        std::cout << "adding " << tempName << " to " << context.getFrameSize() + aItemSOffset << "(sp)" << std::endl;

        context.addToSymbolTable(context.getScopeSymTable(), tempName, arrayItem);

    }

}

void arrayDeclarator::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {
    // not sure we have to do this one
}

void arrayDeclarator::Print(std::ostream &stream) const {
    direct_declarator_->Print(stream);
    stream << "[";
    constant_expression_->Print(stream);
    stream << "];" << std::endl;
}
