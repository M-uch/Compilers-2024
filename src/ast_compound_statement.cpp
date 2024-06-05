#include "ast/ast_compound_statement.hpp"
#include "ast/ast_default_statement.hpp"
#include "ast/ast_case_statement.hpp"

void compoundStatement::EmitRISC(std::ostream &stream, Context &context) const {

    if ((statement_list_ == nullptr) && (declaration_list_ == nullptr)) {
        std::cout << "Compound statement returning null" << std::endl;
    } else {
        context.enterScope();
        if (declaration_list_ == nullptr) {
            statement_list_->EmitRISC(stream, context);
        } else if (statement_list_ == nullptr) {
            declaration_list_->EmitRISC(stream,context);
        } else {
            declaration_list_->EmitRISC(stream,context);
            statement_list_->EmitRISC(stream, context);
        }
        context.exitScope();
    }
}

void compoundStatement::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {

    std::cout << "IN COMPOUND STATEMENT - DOING SWITCH STATEMENT" << std::endl;

    // enter new scope
    context.enterScope();

    // assume only statements (case statements)
    int i = 0;
    bool defExists;
    std::string caseReg = context.allocateRegister(stream);
    // iterate through all and make labels
    for (Node *statement : statement_list_->getNodes()) {

        // dynamic casts
        defaultStatement *defState = dynamic_cast<defaultStatement*>(statement);
        caseStatement *caseState = dynamic_cast<caseStatement*>(statement);

        if (caseState != nullptr) {

            //find case condition
            caseState->getConstExp()->EmitRISC(stream, context, caseReg);
            stream << "beq " << destReg << ", " << caseReg << ", CASE" << i << std::endl;

        } else if (defState != nullptr) { // default case
            stream << "beq zero, zero, DEFAULT" << context.getSwLabNum() << std::endl;

        } else {
            std::cout << "ERROR: NO CASE OR DEFAULT" << std::endl;
        }

        i++;
    }

    int j = 0;

    for (Node *statement : statement_list_->getNodes()) {

        // dynamic casts
        defaultStatement *defState = dynamic_cast<defaultStatement*>(statement);
        caseStatement *caseState = dynamic_cast<caseStatement*>(statement);

        if (caseState != nullptr) {

            // put label:
            stream << "CASE" << j << ":" << std::endl;

            caseState->getStatement()->EmitRISC(stream, context);

        } else if (defState != nullptr) { // default case

            stream << "DEFAULT" << context.getSwLabNum() << ":" << std::endl;
            defState->EmitRISC(stream, context);

        } else {
            std::cout << "ERROR: NO CASE OR DEFAULT" << std::endl;
            statement->EmitRISC(stream, context);
        }

        j++;
    }

    context.exitScope();
}

void compoundStatement::Print(std::ostream &stream) const {

    if (declaration_list_ == nullptr) {
        statement_list_->Print(stream);
    } else if (statement_list_ == nullptr) {
        declaration_list_->Print(stream);
    } else {
        declaration_list_->Print(stream);
        statement_list_->Print(stream);
    }
}
