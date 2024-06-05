#include "ast/ast_type_specifier.hpp"

void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context) const {}
void TypeSpecifier::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {}

void TypeSpecifier::Print(std::ostream &stream) const
{
    stream << type_ << " ";
}
