#ifndef AST_DECLARATION_HPP
#define AST_DECLARATION_HPP

#include "ast_node.hpp"

class Declaration : public Node {

    private:

        Node *declaration_specifiers_;
        Node *init_declarator_list_;

    public:

        // Consturctor
        Declaration(Node *declaration_specifiers, Node *init_declarator_list) : declaration_specifiers_(declaration_specifiers), init_declarator_list_(init_declarator_list){};

        // Destructor
        ~Declaration() {delete declaration_specifiers_; delete init_declarator_list_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
    Node *getDeclarationSpecifiers() const{
        return declaration_specifiers_;
    }
    Node *getInitDeclaratorList() const{
        return init_declarator_list_;
    }
};

#endif
