#ifndef AST_DIRECT_DECLARATOR_HPP
#define AST_DIRECT_DECLARATOR_HPP

#include "ast_node.hpp"

class DirectDeclarator : public Node
{
private:
    Node *identifier_;
    NodeList *paramList_;

public:

    // Constructor
    DirectDeclarator(Node *identifier, NodeList *paramList) : identifier_(identifier), paramList_(paramList){}; // same here

    // Destructor
    ~DirectDeclarator()
    {
        delete identifier_;

        if (paramList_ != nullptr) {
            delete paramList_;
        }
    };
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
    Node *getIdentifier() const{
        return identifier_;
    }
    bool getIsFunc() {
        return true;
    }
};

#endif
