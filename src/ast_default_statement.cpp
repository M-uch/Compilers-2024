#include "ast/ast_default_statement.hpp"

void defaultStatement::EmitRISC(std::ostream &stream, Context &context) const {

    // unconditionally do statement if this is called?
    // do the handeling later?
    statement_->EmitRISC(stream, context);
}
void defaultStatement::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {
    // unconditionally do statement if this is called?
    // do the handeling later?
    statement_->EmitRISC(stream, context, destReg);
}
void defaultStatement::Print(std::ostream &stream) const {
    stream << "default: ";
    statement_->Print(stream);
    stream << std::endl;
}
