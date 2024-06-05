#include "ast/operators/BinaryOp/ast_division.hpp"

Division::Division(Node* _left, Node* _right)
    : left(_left), right(_right) {}

Division::~Division() {
    delete left;
    delete right;
}

void Division::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "/";
    right->Print(stream);
    stream << ")";
}

void Division::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN Division" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "div a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void Division::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN Division W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "div " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


