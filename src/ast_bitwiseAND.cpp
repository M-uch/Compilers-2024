#include "ast/operators/BinaryOp/ast_BitwiseAND.hpp"

BitwiseAND::BitwiseAND(Node* _left, Node* _right)
    : left(_left), right(_right) {}

BitwiseAND::~BitwiseAND() {
    delete left;
    delete right;
}

void BitwiseAND::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "&";
    right->Print(stream);
    stream << ")";
}

void BitwiseAND::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN BitwiseAND" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "and a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void BitwiseAND::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN BitwiseAND W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "and " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


