#include "ast/ast_direct_declarator.hpp"
#include "ast/ast_param_list.hpp"
#include "ast/ast_identifier.hpp"

void DirectDeclarator::EmitRISC(std::ostream &stream, Context &context) const
{
    std::cout << "IN DIRECT DECLARATOR" << std::endl;
    // deal with identifier
    if (identifier_ != nullptr) {
        std::cout << "IN IF" << std::endl;
        Identifier* funcID = dynamic_cast<Identifier*>(getIdentifier());
        stream << ".globl " << funcID->getID() <<  std::endl;
        identifier_->EmitRISC(stream, context);
        stream << ":" << std::endl;
        context.enterFunction(stream);
    } else {
        std::cout << "Could not find identifier" << std::endl;
    }

    // deal with parameters IF we have them
    if (paramList_ != nullptr) {
        //ParamList *paramList = dynamic_cast<ParamList*>(paramList_);
        paramList_->EmitRISC(stream, context);
    }
}

void DirectDeclarator::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {}

void DirectDeclarator::Print(std::ostream &stream) const
{
    identifier_->Print(stream);

    stream << "(";
    if (paramList_ != nullptr) {
        paramList_->Print(stream);
    }
    stream << ")";
}
