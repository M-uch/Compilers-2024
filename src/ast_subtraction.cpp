#include "ast/operators/BinaryOp/ast_subtraction.hpp"

Subtraction::Subtraction(Node* _left, Node* _right)
    : left(_left), right(_right) {}

Subtraction::~Subtraction() {
    delete left;
    delete right;
}

void Subtraction::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "-";
    right->Print(stream);
    stream << ")";
}

void Subtraction::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN Subtraction" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "sub a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void Subtraction::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN Subtraction W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "sub " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


