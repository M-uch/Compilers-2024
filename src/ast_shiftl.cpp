#include "ast/operators/BinaryOp/ast_ShiftL.hpp"

LShift::LShift(Node* _left, Node* _right)
    : left(_left), right(_right) {}

LShift::~LShift() {
    delete left;
    delete right;
}

void LShift::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "+";
    right->Print(stream);
    stream << ")";
}

void LShift::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN LShift" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "sll a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void LShift::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN LShift W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "sll " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


