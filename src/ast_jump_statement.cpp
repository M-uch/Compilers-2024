#include "ast/keywords/ast_jump_statement.hpp"
#include "ast/ast_identifier.hpp"

void ReturnStatement::EmitRISC(std::ostream &stream, Context &context) const
{

    // We need to check if experssion_ is in the symbol table...
    // If it is then we have to store its value into a0...
    // then return a0
    std::cout << "IN RETURN" << std::endl;

    if (expression_ != nullptr) {

        Identifier* id = dynamic_cast<Identifier*>(expression_);
        // if the expression we are returning is an 'x' or something else
        if (id != nullptr) {
            std::string var_name = id->getID();
            std::map<std::string, Variable> currScope = context.getScopeSymTable(); // get symbol table
            auto varLoc = currScope.find(var_name); //search map

            // if variable is in symbol table
            if (varLoc != currScope.end()) {

                Variable returnVariable = varLoc->second;
                int offset = context.getFrameSize() + returnVariable.stackoffset_;
                // return the variable value
                stream << "lw a0, " << offset << "(sp)" << std::endl;
                stream << "beq zero, zero, " << context.makeLabel() << std::endl;
                std::cout << "REACHING RETURN" << std::endl;
            } else {

                std::cout << "Variable " << var_name << " not found in symbol table" << std::endl;
            }
        } else {

            // make return flag true
            context.retTrue();
            expression_->EmitRISC(stream, context);
        }
    }

    // context.exitFunction(stream);

    // PREVIOUS IMPLEMENTATION (DEFAULT)
    // if (expression_ != nullptr)
    // {
    //     expression_->EmitRISC(stream, context);
    // }
    // stream << "ret" << std::endl;
}

void ReturnStatement::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {}

void ReturnStatement::Print(std::ostream &stream) const
{
    stream << "return";
    if (expression_ != nullptr)
    {
        stream << " ";
        expression_->Print(stream);
    }
    stream << ";" << std::endl;
}
