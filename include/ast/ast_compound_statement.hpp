#ifndef AST_COMPOUND_STATEMENT_HPP
#define AST_COMPOUND_STATEMENT_HPP

#include "ast_node.hpp"

class compoundStatement : public Node
{
private:
    NodeList *declaration_list_;
    NodeList *statement_list_;

public:

    // Constructor
    compoundStatement(NodeList *declaration_list, NodeList *statement_list) : declaration_list_(declaration_list), statement_list_(statement_list){}; // same here

    // Destructor
    ~compoundStatement() { delete declaration_list_; delete statement_list_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
    NodeList *getDecList() const{
        return declaration_list_;
    }
    NodeList *getStateList() const{
        return statement_list_;
    }
};

#endif
