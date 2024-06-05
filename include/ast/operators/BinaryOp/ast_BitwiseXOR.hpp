#ifndef AST_BITWISEXOR_HPP
#define AST_BITWISEXOR_HPP

#include "ast/ast_node.hpp"

class BitwiseXOR : public Node {
public:
    Node* left;
    Node* right;

    BitwiseXOR(Node* left, Node* right);
    virtual ~BitwiseXOR();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
