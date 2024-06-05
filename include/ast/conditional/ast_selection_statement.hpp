#ifndef AST_SELECTION_STATEMENT_HPP
#define AST_SELECTION_STATEMENT_HPP

#include "ast/ast_node.hpp"

class selectionStatement : public Node {

    private:

        Node *ifExp_;
        Node *ifState_;
        Node *elseState_;

    public:

        // Consturctor
        selectionStatement(Node *ifExp, Node *ifState, Node *elseState) : ifExp_(ifExp), ifState_(ifState), elseState_(elseState){};

        // Destructor
        ~selectionStatement() {delete ifExp_; delete ifState_; delete elseState_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;

};

#endif
