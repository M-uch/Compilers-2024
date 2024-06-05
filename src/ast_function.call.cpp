#include "ast/functions/ast_function_call.hpp"
#include "ast/ast_identifier.hpp"

void funcCall::EmitRISC(std::ostream &stream, Context &context) const {

    if (!context.getExFuncFlag()) {
        std::cout << "External Func flag is False" << std::endl;
        // for each node (argument expression in argument expression list) emit risc and store in argument register
        // f(1, 2)
        // if we have arguments
        if (argument_expression_list_ != nullptr)
        {
            // postfix_expression_->EmitRISC(stream, context);
            argument_expression_list_->EmitRISC(stream, context);
            Identifier *id = dynamic_cast<Identifier*>(postfix_expression_);
            std::string funcID = id->getID();
            stream << "call " << funcID << std::endl;

        } else  { // we have no arguments (e.g 'f()' )
            std::cout << "NO ARGUMENTS" << std::endl;
            Identifier *id = dynamic_cast<Identifier*>(postfix_expression_);
            std::string funcID = id->getID();
            stream << "call " << funcID << std::endl;
        }

    } else {    // is a useless function
        std::cout << "External Func flag is True" << std::endl;
        // dynamic cast to identifier
        Identifier *id = dynamic_cast<Identifier*>(postfix_expression_);
        // still need to store params in arg regs even if useless
        if (argument_expression_list_ != nullptr) {
            argument_expression_list_->EmitRISC(stream, context);
        }

        std::string funcID = id->getID();
        stream << "call " << funcID << std::endl;
        context.exFuncFalse();
    }
}

void funcCall::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {}

void funcCall::Print(std::ostream &stream) const{
    if (argument_expression_list_ != nullptr)
        {
        postfix_expression_->Print(stream);
        argument_expression_list_->Print(stream);
    }
}
