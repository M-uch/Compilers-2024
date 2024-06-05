#ifndef AST_SHIFTL_HPP
#define AST_SHIFTL_HPP

#include "ast/ast_node.hpp"

class LShift : public Node {
public:
    Node* left;
    Node* right;

    LShift(Node* left, Node* right);
    virtual ~LShift();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
