#include "ast/operators/BinaryOp/ast_LogicalOR.hpp"

LogicalOR::LogicalOR(Node* _left, Node* _right)
    : left(_left), right(_right) {}

LogicalOR::~LogicalOR() {
    delete left;
    delete right;
}

void LogicalOR::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "||";
    right->Print(stream);
    stream << ")";
}

void LogicalOR::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN LogicalOR" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    //need to include dynamic labels if we want to use multiple occurences of || in a program
    stream << "bne " << regL << ", zero, .L2" <<  std::endl;
    stream << "beq " << regR << ", zero, .L3" <<  std::endl;
    stream << ".L2:\n" << std::endl;
    stream << "li " << regR << ", 1" <<  std::endl;
    stream << "j .L5\n" << std::endl;
    stream << ".L3:\n" << std::endl;
    stream << "li " << regR << ", 0" << std::endl;
    stream << ".L5:\n" << std::endl;
    stream << "mv a0" << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void LogicalOR::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN LogicalOR W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "bne " << regL << ", zero, .L2" << "\n" << std::endl;
    stream << "beq " << regR << ", zero, .L3" << "\n" << std::endl;
    stream << ".L2:\n" << std::endl;
    stream << "li " << regR << ", 1" << "\n" << std::endl;
    stream << "j .L5\n" << std::endl;
    stream << ".L3:\n" << std::endl;
    stream << "li " << regR << ", 0" << "\n" << std::endl;
    stream << ".L5:\n" << std::endl;
    stream << "mv " << destReg << ", " << regR << "\n" << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


