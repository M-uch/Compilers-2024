#ifndef AST_PARAM_DECLARATION_HPP
#define AST_PARAM_DECLARATION_HPP

#include "ast_node.hpp"

class paramDeclaration : public Node
{
    private:

        Node *specifier_;
        Node *declarator_;

    public:

        paramDeclaration(Node *specifier, Node *declarator) : specifier_(specifier), declarator_(declarator){};
        ~paramDeclaration(){ delete specifier_; delete declarator_; };

        void EmitRISC(std::ostream &stream, Context &context) const override;
        void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
        void Print(std::ostream &stream) const override;

        Node *getSpecifier() const{
            return specifier_;
        }
        Node *getDec() const{
            return declarator_;
        }
};

#endif
