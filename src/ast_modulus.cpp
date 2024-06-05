#include "ast/operators/BinaryOp/ast_modulus.hpp"

Modulus::Modulus(Node* _left, Node* _right)
    : left(_left), right(_right) {}

Modulus::~Modulus() {
    delete left;
    delete right;
}

void Modulus::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "%";
    right->Print(stream);
    stream << ")";
}

void Modulus::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN Modulus" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "rem a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void Modulus::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN Modulus W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "rem " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


