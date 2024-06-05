#ifndef AST_INIT_DECLARATOR_HPP
#define AST_INIT_DECLARATOR_HPP

#include "ast_node.hpp"

class initDeclarator : public Node {

    private:

        Node *declarator_;
        Node *initialiser_;

    public:

        // Consturctor
        initDeclarator(Node *declarator, Node *initialiser) : declarator_(declarator), initialiser_(initialiser){};

        // Destructor
        ~initDeclarator() {delete declarator_; delete initialiser_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
    Node *getDeclarator() const{
        return declarator_;
    }
    Node *getInitialiser() const{
        return initialiser_;
    }
};

#endif
