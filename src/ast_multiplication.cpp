#include "ast/operators/BinaryOp/ast_multiplication.hpp"

Multiplication::Multiplication(Node* _left, Node* _right)
    : left(_left), right(_right) {}

Multiplication::~Multiplication() {
    delete left;
    delete right;
}

void Multiplication::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "+";
    right->Print(stream);
    stream << ")";
}

void Multiplication::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN Multiplication" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "mul a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void Multiplication::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN Multiplication W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "mul " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


