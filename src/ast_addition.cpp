#include "ast/operators/BinaryOp/ast_addition.hpp"

Addition::Addition(Node* _left, Node* _right)
    : left(_left), right(_right) {}

Addition::~Addition() {
    delete left;
    delete right;
}

void Addition::Print(std::ostream &stream) const {
    stream << "(";
    left->Print(stream);
    stream << "+";
    right->Print(stream);
    stream << ")";
}

void Addition::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN ADDITION" << std::endl;


    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "add a0" << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


void Addition::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN ADDITION W/ DESTREG" << std::endl;

    std::string regL = context.allocateRegister(stream);
    std::string regR = context.allocateRegister(stream);

    std::cout << "reg_left = " << regL << std::endl;
    std::cout << "reg_right = " << regR << std::endl;

    left->EmitRISC(stream, context, regL);
    right->EmitRISC(stream, context, regR);

    stream << "add " << destReg << ", " << regL << ", " << regR << std::endl;

    context.deallocateRegister(regL);
    context.deallocateRegister(regR);
}


