#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ast/conditional/ast_for.hpp"
#include "ast/conditional/ast_selection_statement.hpp"
#include "ast/conditional/ast_while.hpp"

#include "ast/functions/ast_function_call.hpp"
#include "ast/functions/ast_function_definition.hpp"

#include "ast/keywords/ast_jump_statement.hpp"

#include "ast/operators/BinaryOp/ast_addition.hpp"
#include "ast/operators/BinaryOp/ast_subtraction.hpp"
#include "ast/operators/BinaryOp/ast_multiplication.hpp"
#include "ast/operators/BinaryOp/ast_division.hpp"
#include "ast/operators/BinaryOp/ast_modulus.hpp"
#include "ast/operators/BinaryOp/ast_ShiftL.hpp"
#include "ast/operators/BinaryOp/ast_ShiftR.hpp"
#include "ast/operators/BinaryOp/ast_BitwiseAND.hpp"
#include "ast/operators/BinaryOp/ast_BitwiseOR.hpp"
#include "ast/operators/BinaryOp/ast_BitwiseXOR.hpp"
#include "ast/operators/BinaryOp/ast_LogicalAND.hpp"
#include "ast/operators/BinaryOp/ast_LogicalOR.hpp"
#include "ast/operators/BinaryOp/ast_LessThan.hpp"
#include "ast/operators/BinaryOp/ast_LessThanEQ.hpp"
#include "ast/operators/BinaryOp/ast_GreaterThan.hpp"
#include "ast/operators/BinaryOp/ast_GreaterThanEQ.hpp"
#include "ast/operators/BinaryOp/ast_Equal.hpp"
#include "ast/operators/BinaryOp/ast_EqualNot.hpp"
#include "ast/operators/UnaryOp/ast_decrement.hpp"
#include "ast/operators/UnaryOp/ast_increment.hpp"

#include "ast/ast_direct_declarator.hpp"
#include "ast/ast_identifier.hpp"
#include "ast/ast_node.hpp"
#include "ast/ast_type_specifier.hpp"
#include "ast/ast_constant.hpp"
#include "ast/ast_context.hpp"
#include "ast/ast_param_declaration.hpp"
#include "ast/ast_param_list.hpp"
#include "ast/ast_init_declarator.hpp"
#include "ast/ast_declaration.hpp"
#include "ast/ast_assignment_expression.hpp"
#include "ast/ast_compound_statement.hpp"
#include "ast/ast_argument_expression_list.hpp"
#include "ast/ast_null.hpp"
#include "ast/ast_array_declarator.hpp"
#include "ast/ast_array_indexing.hpp"
#include "ast/ast_continue.hpp"
#include "ast/ast_break.hpp"
#include "ast/ast_case_statement.hpp"
#include "ast/ast_default_statement.hpp"
#include "ast/ast_switch_statement.hpp"

extern Node *ParseAST(std::string file_name);

#endif
