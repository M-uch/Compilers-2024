#ifndef AST_LESSTHANEQ_HPP
#define AST_LESSTHANEQ_HPP

#include "ast/ast_node.hpp"

class LessThanEQ : public Node {
public:
    Node* left;
    Node* right;

    LessThanEQ(Node* left, Node* right);
    virtual ~LessThanEQ();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
