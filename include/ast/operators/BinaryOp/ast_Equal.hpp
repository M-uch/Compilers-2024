#ifndef AST_EQUAL_HPP
#define AST_EQUAL_HPP

#include "ast/ast_node.hpp"

class Equal : public Node {
public:
    Node* left;
    Node* right;

    Equal(Node* left, Node* right);
    virtual ~Equal();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
