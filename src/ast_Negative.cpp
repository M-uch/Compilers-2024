#include "ast/operators/UnaryOp/ast_Negative.hpp"

void Negative::EmitRISC(std::ostream &stream, Context &context) const {

    // do Negative
    std::string NegativeReg = context.allocateRegister(stream);
    unary_expression_->EmitRISC(stream, context, NegativeReg);

    stream << "neg a0 " << ", " << NegativeReg << std::endl;
}

void Negative::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    // do Negative
    std::string NegativeReg = context.allocateRegister(stream);
    unary_expression_->EmitRISC(stream, context, NegativeReg);

    stream << "neg " << destReg << ", " << NegativeReg << std::endl;
}

void Negative::Print(std::ostream &stream) const {
    unary_expression_->Print(stream);
    stream << " -";
}
