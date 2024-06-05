#include "ast/operators/BinaryOp/ast_Equal.hpp"

Equal::Equal(Node* _left, Node* _right)
    : left(_left), right(_right) {}

Equal::~Equal() {
    delete left;
    delete right;
}

void Equal::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "==";
    right->Print(stream);
    stream << ")";
}

void Equal::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN Equal" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "sub " << regR << ", " << regL << ", " << regR << "\n" << std::endl;
    stream << "seqz " << regR << ", " << regR << "\n" << std::endl;
    stream << "andi " << regR << ", " << regR << ", " << "0xff" << "\n" << std::endl;
    stream << "mv " << "a0" << ", " << regR << "\n" << std::endl;
    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void Equal::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN Equal W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "sub " << regR << ", " << regL << ", " << regR << "\n" << std::endl;
    stream << "seqz " << regR << ", " << regR << "\n" << std::endl;
    stream << "andi " << regR << ", " << regR << ", " << "0xff" << "\n" << std::endl;
    stream << "mv " << destReg << ", " << regR << "\n" << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


