#include "ast/ast_null.hpp"

    void nullHandler::EmitRISC(std::ostream &stream, Context &context) const {
        stream << "nop" << std::endl;
    }

    void nullHandler::EmitRISC(std::ostream &stream, Context &context, const std::string &destReg) const {
        stream << "nop" << std::endl;
    }

    void nullHandler::Print(std::ostream &stream) const {
        stream << std::endl;
    }
