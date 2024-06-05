#include "ast/operators/UnaryOp/ast_LogicalNOT.hpp"

void LogicalNOT::EmitRISC(std::ostream &stream, Context &context) const {

    // do LogicalNOT
    std::string LogicalNOTreg = context.allocateRegister(stream);
    unary_expression_->EmitRISC(stream, context, LogicalNOTreg);

    stream << "seqz " << LogicalNOTreg << ", " << LogicalNOTreg << std::endl;
    stream << "andi " << LogicalNOTreg << ", " << LogicalNOTreg << ", " << "0xff" <<std::endl;
    stream << "mv a0 " << ", " << LogicalNOTreg << std::endl;
}

void LogicalNOT::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    // do LogicalNOT
    std::string LogicalNOTreg = context.allocateRegister(stream);
    unary_expression_->EmitRISC(stream, context, LogicalNOTreg);

    stream << "seqz " << LogicalNOTreg << ", " << LogicalNOTreg << std::endl;
    stream << "andi " << LogicalNOTreg << ", " << LogicalNOTreg << ", " << "0xff" <<std::endl;
    stream << "mv " << destReg << ", " << LogicalNOTreg << std::endl;
}


void LogicalNOT::Print(std::ostream &stream) const {
    unary_expression_->Print(stream);
    stream << " !";
}
