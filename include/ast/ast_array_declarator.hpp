#ifndef AST_ARRAY_DECLARATOR_HPP
#define AST_ARRAY_DECLARATOR_HPP

#include "ast_node.hpp"

class arrayDeclarator : public Node
{
private:
    Node *direct_declarator_;
    Node *constant_expression_;

public:
    arrayDeclarator(Node *direct_declarator, Node *constant_expression) : direct_declarator_(direct_declarator), constant_expression_(constant_expression) {}
    ~arrayDeclarator() {delete direct_declarator_; delete constant_expression_;};

    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
    void Print(std::ostream &stream) const override;
    Node* getDirDec() const{
        return direct_declarator_;
    }
};

#endif
