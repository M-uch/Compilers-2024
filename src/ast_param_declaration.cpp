#include "ast/ast_param_declaration.hpp"

void paramDeclaration::Print(std::ostream &stream) const {
    specifier_->Print(stream);
    declarator_->Print(stream);
}

void paramDeclaration::EmitRISC(std::ostream &stream, Context &context) const /*override*/ {
    // Implementation here, even if it's empty
}

void paramDeclaration::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {}
