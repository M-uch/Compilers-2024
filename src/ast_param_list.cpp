#include "ast/ast_param_list.hpp"
#include "ast/ast_context.hpp"
#include "ast/ast_param_declaration.hpp"
#include "ast/ast_type_specifier.hpp" // Assume this exists and represents type information
#include "ast/ast_direct_declarator.hpp" // Assume this exists and represents identifier information
#include "ast/ast_identifier.hpp"

void ParamList::EmitRISC(std::ostream &stream, Context &context) const{

    // Store values in argument registers into stack (define 128)
    // sw ax, 128-x(sp) - note a0-7

    std::cout << "IN PARAM LIST" << std::endl;

    // use dynamic casts to get the type and symbol table and emit store word
    int i = 0;
    // std::map<std::string, Variable> symTable = context.getScopeSymTable();
    for (Node *param : getNodes()) { // need to find paramList actually and will need to also dynamically cast declarator to direct declarator
        // param->EmitRISC(stream, context);
        std::cout << "i = " << i << std::endl;
        // dynamic casts - this gets the values that we need
        paramDeclaration *paramDecl = dynamic_cast<paramDeclaration*>(param); // define param as param declaration
        TypeSpecifier *typeSpec = dynamic_cast<TypeSpecifier*>(paramDecl->getSpecifier());
        Identifier *paramID = dynamic_cast<Identifier*>(paramDecl->getDec()); // NOTE: we skip directDeclarator because we know that it will just be an identifier

        // now get the values we want
        std::string type = typeSpec->getType();
        std::string id = paramID->getID();
        std::cout << "type is " << type << std::endl;
        std::cout << "id is " << id << std::endl;

        // create variable object for param
        Variable var(type, context.getOffset(type), i*context.getOffset(type) - 12);
        std::cout << "offset for type " << type << " is " << context.getOffset(type) << std::endl;
        std::cout << "stack offset for " << i << " parameter is " << i*context.getOffset(type) - 12 << std::endl;

        // add the parameter to the symbol table
        // context.addToSymbolTable(symTable, id, var);
        context.addToSymbolTable(context.getScopeSymTable(), id, var);
        std::cout << "Sym table size is now: " << context.getScopeSymTable().size() << std::endl;

        // find free Arg register
        int freeArgReg = context.allocateParameter();
        std::cout << "freeArgReg is a" << freeArgReg << std::endl;
        context.makeUsed(freeArgReg+10);

        stream << "sw " << "a" << freeArgReg << "," << (context.getFrameSize() + i*context.getOffset(type) - 12) << "(sp)" << std::endl;
        i++;
    }
}

