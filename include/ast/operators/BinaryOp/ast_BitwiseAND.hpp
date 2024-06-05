#ifndef AST_BITWISEAND_HPP
#define AST_BITWISEAND_HPP

#include "ast/ast_node.hpp"

class BitwiseAND : public Node {
public:
    Node* left;
    Node* right;

    BitwiseAND(Node* left, Node* right);
    virtual ~BitwiseAND();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
