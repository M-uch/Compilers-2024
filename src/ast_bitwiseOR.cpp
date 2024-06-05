#include "ast/operators/BinaryOp/ast_BitwiseOR.hpp"

BitwiseOR::BitwiseOR(Node* _left, Node* _right)
    : left(_left), right(_right) {}

BitwiseOR::~BitwiseOR() {
    delete left;
    delete right;
}

void BitwiseOR::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "|";
    right->Print(stream);
    stream << ")";
}

void BitwiseOR::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN BitwiseOR" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "or a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void BitwiseOR::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN BitwiseOR W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "or " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


