#ifndef AST_OPERATORS_HPP
#define AST_OPERATORS_HPP

#include "ast/ast_node.hpp"

// UNUSED

// class Template : public Node {
// public:
//     Node* left;
//     Node* right;

//     Template(Node* left, Node* right);
//     virtual ~Template();

//     void Print(std::ostream &stream) const override;
//     void EmitRISC(std::ostream &stream, Context &context) const override;
//     void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
// };

class Addition : public Node {
public:
    Node* left;
    Node* right;

    Addition(Node* left, Node* right);
    virtual ~Addition();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

class Subtraction : public Node {
public:
    Node* left;
    Node* right;

    Subtraction(Node* left, Node* right);
    virtual ~Subtraction();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

class Multiplication : public Node {
public:
    Node* left;
    Node* right;

    Multiplication(Node* left, Node* right);
    virtual ~Multiplication();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

class Division : public Node {
public:
    Node* left;
    Node* right;

    Division(Node* left, Node* right);
    virtual ~Division();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

class Modulus : public Node {
public:
    Node* left;
    Node* right;

    Modulus(Node* left, Node* right);
    virtual ~Modulus();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

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

class RShift : public Node {
public:
    Node* left;
    Node* right;

    RShift(Node* left, Node* right);
    virtual ~RShift();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

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

class LessThan : public Node {
public:
    Node* left;
    Node* right;

    LessThan(Node* left, Node* right);
    virtual ~LessThan();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

class GreaterThan : public Node {
public:
    Node* left;
    Node* right;

    GreaterThan(Node* left, Node* right);
    virtual ~GreaterThan();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

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

class GreaterThanEQ : public Node {
public:
    Node* left;
    Node* right;

    GreaterThanEQ(Node* left, Node* right);
    virtual ~GreaterThanEQ();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

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

class NotEqual : public Node {
public:
    Node* left;
    Node* right;

    NotEqual(Node* left, Node* right);
    virtual ~NotEqual();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

class LogicalAND : public Node {
public:
    Node* left;
    Node* right;

    LogicalAND(Node* left, Node* right);
    virtual ~LogicalAND();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

class LogicalOR : public Node {
public:
    Node* left;
    Node* right;

    LogicalOR(Node* left, Node* right);
    virtual ~LogicalOR();

    void Print(std::ostream &stream) const override;
    void EmitRISC(std::ostream &stream, Context &context) const override;
    void EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const override;
};

#endif
