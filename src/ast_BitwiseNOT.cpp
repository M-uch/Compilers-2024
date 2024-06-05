#include "ast/operators/UnaryOp/ast_BitwiseNOT.hpp"

void BitwiseNOT::EmitRISC(std::ostream &stream, Context &context) const {

    // do BitwiseNOT
    std::string BitwiseNOTreg = context.allocateRegister(stream);
    unary_expression_->EmitRISC(stream, context, BitwiseNOTreg);

    stream << "not a0 " << ", " << BitwiseNOTreg << std::endl;
}

void BitwiseNOT::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    // do BitwiseNOT
    std::string BitwiseNOTreg = context.allocateRegister(stream);
    unary_expression_->EmitRISC(stream, context, BitwiseNOTreg);

    stream << "not " << destReg << ", " << BitwiseNOTreg << std::endl;
}

void BitwiseNOT::Print(std::ostream &stream) const {
    unary_expression_->Print(stream);
    stream << " ~";
}
