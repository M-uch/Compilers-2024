#ifndef AST_BITWISEOR_HPP
#define AST_BITWISEOR_HPP

#include "ast/ast_node.hpp"

class BitwiseOR : public Node {
public:
    Node* left;
    Node* right;

    BitwiseOR(Node* left, Node* right);
    virtual ~BitwiseOR();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
