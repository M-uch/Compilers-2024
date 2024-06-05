#include "ast/operators/BinaryOp/ast_BitwiseXOR.hpp"

BitwiseXOR::BitwiseXOR(Node* _left, Node* _right)
    : left(_left), right(_right) {}

BitwiseXOR::~BitwiseXOR() {
    delete left;
    delete right;
}

void BitwiseXOR::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "^";
    right->Print(stream);
    stream << ")";
}

void BitwiseXOR::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN BitwiseXOR" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "xor a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void BitwiseXOR::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN BitwiseXOR W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "xor " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


