#include "ast/ast_case_statement.hpp"

void caseStatement::EmitRISC(std::ostream &stream, Context &context) const {}
void caseStatement::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {}
void caseStatement::Print(std::ostream &stream) const {
    stream << "Case: ";
    constant_expression_->Print(stream);
    stream << " :" << std::endl;
}
