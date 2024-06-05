#include "ast/functions/ast_function_definition.hpp"
// #include "ast_direct_declarator.hpp"

void FunctionDefinition::EmitRISC(std::ostream &stream, Context &context) const
{
    // Emit assembler directives.
    // TODO: these are just examples ones, make sure you understand
    // the concept of directives and correct them.
    std::cout << "IN FUNCTION DEFINITION" << std::endl;

    stream << ".text" << std::endl;
    // stream << ".globl f" << std::endl;

    // TODO: MAKE LABEL
    // MAKE NEW SCOPE
    // Function newScope;
    // context.enterFunction(newScope, stream); // FIX THIS


    // NEED TO:
    // Take parameters and add them into the stack
    // also add those paramters to the symbol table of the scope
    std::cout << "Scope size before function definition is " << context.getScopeStack().size() << std::endl;

    // Set up new scope
    if (context.getScopeStack().size() == 0) { // no global variables or anything
        Function newScope;
        context.pushToStack(newScope);
    } else{ // need to keep global variables
        context.enterScope();
    }
    // Identifier *id dynamic_cast
    declarator_->EmitRISC(stream, context);
    // context.enterFunction(stream); // FIX THIS

    // Does everything inside function
    if (compound_statement_ != nullptr)
    {
        std::cout << "COMPOUND STATEMENT START" << std::endl;
        compound_statement_->EmitRISC(stream, context);
        std::cout << "COMPOUND STATEMENT FINISHED" << std::endl;
    }

    // EXIT FUNCTION
    context.exitFunction(stream);
}

void FunctionDefinition::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {}

void FunctionDefinition::Print(std::ostream &stream) const
{
    declaration_specifiers_->Print(stream);
    stream << " ";

    declarator_->Print(stream);
    stream << "{" << std::endl;

    if (compound_statement_ != nullptr)
    {
        compound_statement_->Print(stream);
    }
    stream << "}" << std::endl;
}
