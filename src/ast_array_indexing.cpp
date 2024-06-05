#include "ast/ast_array_indexing.hpp"
#include "ast/ast_identifier.hpp"

void arrayIndexing::EmitRISC(std::ostream &stream, Context &context) const {

    // assume returning
    std::cout << "RETURNING ARRAY INDEX" << std::endl;
    // dynamic casts
    Identifier *id = dynamic_cast<Identifier*>(postfix_expression_);

    std::string arrayName = id->getID();
    std::cout << "arrayName is " << arrayName << std::endl;
    int arrayPointerOffset = context.getFrameSize() + context.getScopeSymTable().find(arrayName)->second.stackoffset_-4;
    std::cout << "array base address is " << arrayPointerOffset << " + sp " << std::endl;

    // calculate base address
    std::string baseReg = context.allocateRegister(stream);
    stream << "addi " << baseReg << ", sp" << ", " << arrayPointerOffset << std::endl;

    // i * 4
    std::string treg = context.allocateRegister(stream);
    std::cout << "i 'expression' stored in " << treg << std::endl;
    expression_->EmitRISC(stream, context, treg);
    stream << "slli " << treg << ", "  << treg << ", 2" << std::endl;

    // base address + (i * 4)
    stream << "sub " << treg <<  ", " << baseReg << ", " << treg << std::endl;

    // load into return
    stream << "lw a0, " << 0 << "(" << treg << ")" << std::endl;

    context.deallocateRegister(treg);
    context.deallocateRegister(baseReg);

    // // find array pointer offset (e.g i from x[i])
    // std::string arrayItemReg = context.allocateRegister(stream);
    // std::cout << "arrayItemReg is " << arrayItemReg << std::endl;
    // expression_->EmitRISC(stream, context, arrayItemReg);
    // stream << "slli " << arrayItemReg << ", "  << arrayItemReg << ", 2" << std::endl;
    // // slli rd, rs1, 2
    // // now find stack offset
    // std::string tempReg1 = context.allocateRegister(stream);
    // std::string tempReg2 = context.allocateRegister(stream);
    // std::cout << "tempReg1 is "<< tempReg1 << std::endl;
    // std::cout << "tempReg2 is "<< tempReg2 << std::endl;
    // stream << "li " << tempReg1 << ", " << context.getFrameSize() + arrayPointerOffset << std::endl;
    // stream << "sub " << tempReg2 << ", "  << tempReg1 << ", " << arrayItemReg << std::endl;
    // stream << "lw a0, " << 0 << "(" << tempReg2 << ")" << std::endl;
    // stream << "beq, zero, zero, " << context.makeLabel() << std::endl;

    // context.deallocateRegister(tempReg1);
    // context.deallocateRegister(tempReg2);
    // context.deallocateRegister(arrayItemReg);

}

void arrayIndexing::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN ARRAY INDEXING W/ DESTREG" << std::endl;
    // need to put the memory location of x[i] into destReg

    // dynamic casts
    Identifier *id = dynamic_cast<Identifier*>(postfix_expression_);

    std::string arrayName = id->getID();
    std::cout << "arrayName is " << arrayName << std::endl;
    int arrayPointerOffset = context.getFrameSize() + context.getScopeSymTable().find(arrayName)->second.stackoffset_-4;
    std::cout << "array base address is " << arrayPointerOffset << " + sp " << std::endl;

    // calculate base address
    std::string baseReg = context.allocateRegister(stream);
    stream << "addi " << baseReg << ", sp" << ", " << arrayPointerOffset << std::endl;

    // i * 4
    std::string treg = context.allocateRegister(stream);
    std::cout << "i 'expression' stored in " << treg << std::endl;
    expression_->EmitRISC(stream, context, treg);
    stream << "slli " << treg << ", "  << treg << ", 2" << std::endl;

    // base address + (i * 4)
    stream << "sub " << destReg << ", " << baseReg << ", " << treg << std::endl;

    context.deallocateRegister(treg);
    context.deallocateRegister(baseReg);

    // // find array pointer offset (e.g i from x[i])
    // std::string arrayItemReg = context.allocateRegister(stream);
    // std::cout << "arrayItemReg is " << arrayItemReg << std::endl;
    // expression_->EmitRISC(stream, context, arrayItemReg);
    // stream << "slli " << arrayItemReg << ", "  << arrayItemReg << ", 2" << std::endl;
    // // slli rd, rs1, 2
    // // now find stack offset
    // std::string tempReg = context.allocateRegister(stream);
    // std::cout << "tempReg is "<< tempReg << std::endl;
    // stream << "li " << tempReg << ", " << context.getFrameSize() + arrayPointerOffset << std::endl;
    // stream << "sub " << destReg << ", " << tempReg << ", " << arrayItemReg << std::endl;

    // context.deallocateRegister(tempReg);
    // context.deallocateRegister(arrayItemReg);
}

void arrayIndexing::Print(std::ostream &stream) const {

    postfix_expression_->Print(stream);
    stream << "[";
    expression_->Print(stream);
    stream << "];" << std::endl;
}
