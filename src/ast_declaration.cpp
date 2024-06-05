#include "ast/ast_declaration.hpp"
#include "ast/ast_type_specifier.hpp"
#include "ast/ast_init_declarator.hpp"
#include "ast/ast_identifier.hpp"
#include "ast/ast_assignment_expression.hpp"
#include "ast/ast_direct_declarator.hpp"
#include "ast/ast_array_declarator.hpp"

void Declaration::EmitRISC(std::ostream &stream, Context &context) const {

    std::cout << "IN DECLARATION" << std::endl;

    // dynamic casts
    TypeSpecifier *type = dynamic_cast<TypeSpecifier*>(getDeclarationSpecifiers());
    if (type == nullptr) {std::cout << "type returning null" << std::endl;}
    initDeclarator *dec = dynamic_cast<initDeclarator*>(getInitDeclaratorList());
    if (type == nullptr) { std::cout << "initdec returning null" << std::endl;}
    DirectDeclarator *dirdec = dynamic_cast<DirectDeclarator*>(dec->getDeclarator());
    if (dirdec == nullptr) { std::cout << "dirdec retunting null" << std::endl;}
    arrayDeclarator *arrDec = dynamic_cast<arrayDeclarator*>(dec->getDeclarator());
    if (arrDec == nullptr) {std::cout << "arrdec returning null" << std::endl;}

    // if not a function
    if(dirdec == nullptr) {
        std::cout << "NOT A FUNCTION" << std::endl;
        if(arrDec == nullptr) {
            std::cout << "ASSIGNING / DECLARING A VARIABLE" << std::endl;
            Identifier *id = dynamic_cast<Identifier*>(dec->getDeclarator());

            // declaration cannot be a return statement (THIS MIGHT NOT BE NEEDED)
            context.retFalse();

            std::string varType = type->getType();
            std::string varId = id->getID();
            int stackOffset = context.getStackOffset(context.getScopeSymTable(), varType);

            std::cout << "assigning " << varId << " to symbol table" << std::endl;
            std::cout << "Size of symbol table before declaration or assignment statement = " << context.getScopeSymTable().size() << std::endl;
            // add variable to symbol table
            Variable var(varType, context.getOffset(varType), stackOffset);
            context.addToSymbolTable(context.getScopeSymTable(), varId, var);
            std::cout << "Size of symbol table after declaration or assignment statement = " << context.getScopeSymTable().size() << std::endl;

            // if it is an assignment (i.e int x = some value;)
            if (dec != nullptr) {
                std::cout << "In ast_declaration.cpp we are assigning" << std::endl;

                context.updateVarID(varId);
                std::cout << "varId is " << varId << std::endl;
                dec->EmitRISC(stream, context);

            }
        } else {
            std::cout << "DECLARING ARRAY" << std::endl;
            arrDec->EmitRISC(stream, context);
        }

    } else { // function declaration (pointless) therefore do nothing
        context.exFuncTrue();
        std::cout << "USELESS FUNCTION DEFINITION SPOTTED" << std::endl;
    }
}

void Declaration::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {}

// TO DO: PRINT
void Declaration::Print(std::ostream &stream) const{
    initDeclarator *dec = dynamic_cast<initDeclarator*>(getInitDeclaratorList());
    declaration_specifiers_->Print(stream);
    if (dec != nullptr) {
        init_declarator_list_->Print(stream);
    }
}
