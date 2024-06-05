#include "ast/operators/BinaryOp/ast_ShiftR.hpp"

RShift::RShift(Node* _left, Node* _right)
    : left(_left), right(_right) {}

RShift::~RShift() {
    delete left;
    delete right;
}

void RShift::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "+";
    right->Print(stream);
    stream << ")";
}

void RShift::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN RShift" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "sra a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void RShift::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN RShift W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "sra " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


