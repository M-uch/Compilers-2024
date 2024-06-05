// Adapted from: https://www.lysator.liu.se/c/ANSI-C-grammar-y.html

// TODO: you can either continue adding to this grammar file or
// rename parser_full.y to parser.y once you're happy with
// how this example works.

%code requires{
    #include "ast.hpp"

    extern Node *g_root;
    extern FILE *yyin;
    int yylex(void);
    void yyerror(const char *);
}

// Represents the value associated with any kind of AST node.
%union{
  Node         *node;
  NodeList     *nodes;
  int          number_int;
  double       number_float;
  std::string  *string;
  yytokentype  token;
}

%token IDENTIFIER INT_CONSTANT FLOAT_CONSTANT STRING_LITERAL
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%token TYPE_NAME TYPEDEF EXTERN STATIC AUTO REGISTER SIZEOF
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS
%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <node> external_declaration function_definition primary_expression postfix_expression
%type <node> unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression
%type <node> equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type <node> conditional_expression assignment_expression expression constant_expression declaration declaration_specifiers init_declarator_list
%type <node> init_declarator type_specifier struct_specifier struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list
%type <node> struct_declarator enum_specifier enumerator_list enumerator declarator direct_declarator pointer  parameter_declaration
%type <node> identifier_list type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement
%type <node> compound_statement expression_statement selection_statement iteration_statement jump_statement

%type <nodes> statement_list parameter_list declaration_list argument_expression_list translation_unit

%type <string> unary_operator assignment_operator storage_class_specifier

%type <number_int> INT_CONSTANT STRING_LITERAL
%type <number_float> FLOAT_CONSTANT
%type <string> IDENTIFIER


%start ROOT
%%

ROOT
    : translation_unit { g_root = $1; }

translation_unit
	: external_declaration { $$ = new NodeList($1); }
    | translation_unit external_declaration { $1->PushBack($2); $$ = $1;}
	;

external_declaration
	: function_definition { $$ = $1; }
    | declaration {$$=$1;}
	;

function_definition
	: declaration_specifiers declarator compound_statement {
		$$ = new FunctionDefinition($1, $2, $3);
	}
    | declaration_specifiers declarator declaration_list compound_statement
	;

declaration
	: declaration_specifiers ';' {$$ = new Declaration($1, nullptr);}
	| declaration_specifiers init_declarator_list ';' {$$ = new Declaration($1, $2);}
	; // int x = 10, y= 3 ^^

declaration_specifiers
	: type_specifier { $$ = $1; }
	;

init_declarator_list
	: init_declarator {$$ = $1;}

init_declarator
	: declarator {$$ = new initDeclarator($1, nullptr);}
	| declarator '=' initializer {$$ = new initDeclarator($1, $3);}
	;

type_specifier
	: INT {
		$$ = new TypeSpecifier("int");
	}
	;

declarator
	: direct_declarator { $$ = $1; }
	;

direct_declarator
	: IDENTIFIER {
		$$ = new Identifier(*$1);
		delete $1;
	}
	| direct_declarator '(' parameter_list ')' {$$ = new DirectDeclarator($1, $3);}
	| direct_declarator '[' constant_expression ']' {$$ = new arrayDeclarator($1, $3);}
	| direct_declarator '[' ']' {$$ = new nullHandler();}
	| direct_declarator '(' ')' {
		$$ = new DirectDeclarator($1, nullptr);
	}
	;

parameter_list
	: parameter_declaration {$$ = new ParamList($1);}
	| parameter_list ',' parameter_declaration {$$ = $1; $1->PushBack($3);}
	;

parameter_declaration
	: declaration_specifiers declarator {$$ = new paramDeclaration($1, $2);}
	/* | declaration_specifiers abstract_declarator
	| declaration_specifiers */
	;

initializer
	: assignment_expression {$$ = $1;}

statement
	: jump_statement { $$ = $1; }
    | expression_statement{$$ = $1;}
	| selection_statement {$$ =$1;}
	| compound_statement {$$ = $1;}
    | iteration_statement {$$ =$1;}
    | labeled_statement {$$ = $1;}
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement {$$ = new caseStatement($2, $4);}
	| DEFAULT ':' statement {$$ = new defaultStatement($3);}
	;

compound_statement
	: '{' statement_list '}' { $$ = new compoundStatement(nullptr,$2); }
    | '{' declaration_list '}' { $$ = new compoundStatement($2, nullptr);}
    | '{' declaration_list statement_list '}'  { $$ = new compoundStatement($2, $3);}
    | '{' '}' { $$ = new nullHandler();}
	;// statement is any line ending in semi colon (and if and for etc)
	;

declaration_list
	: declaration { $$ = new NodeList{$1};}
	| declaration_list declaration { $1->PushBack($2); $$=$1;}
	;


statement_list
	: statement { $$ = new NodeList($1); }
	| statement_list statement { $1->PushBack($2); $$=$1; }
	;

expression_statement
	: ';'
	| expression ';' { $$ = $1; }
	;

selection_statement
	: IF '(' expression ')' statement {$$ = new selectionStatement{$3, $5, nullptr};}
	| IF '(' expression ')' statement ELSE statement {$$ = new selectionStatement($3, $5, $7);}
    | SWITCH '(' expression ')' statement { $$ = new switchStatement($3, $5);}
    ;

iteration_statement
	: WHILE '(' expression ')' statement {$$ = new whileLoop($3, $5);}
	| DO statement WHILE '(' expression ')' ';'{ $$ = new whileLoop($5, $2);}
	| FOR '(' expression_statement expression_statement ')' statement { $$ = new forLoop($3, $4, nullptr, $6);}
	| FOR '(' expression_statement expression_statement expression ')' statement { $$ = new forLoop($3, $4, $5, $7);}
	;

jump_statement
	: RETURN ';' {
		$$ = new ReturnStatement(nullptr);
	}
	| RETURN expression ';' {
		std::cout << "Parsing return statements" << std::endl;
        $$ = new ReturnStatement($2);
	}
	| CONTINUE ';' {$$ = new Continue();}
	| BREAK ';' {$$ = new Break();}
	;

primary_expression
	: IDENTIFIER { $$ = new Identifier(*$1); delete $1;}
    | INT_CONSTANT {
		$$ = new IntConstant($1);
	}
	;

postfix_expression
	: primary_expression {$$ = $1;}
    | postfix_expression '[' expression ']' { $$ = new arrayIndexing{$1, $3};}
	| postfix_expression '(' ')' {$$ = new funcCall($1, nullptr);}
	| postfix_expression '(' argument_expression_list ')' {$$ = new funcCall($1, $3);}
	/* | postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER*/
	| postfix_expression INC_OP {$$ = new Increment($1);}
	| postfix_expression DEC_OP {$$ = new Decrement($1);}
	;

argument_expression_list
	: assignment_expression {$$= new ArgList($1);}
    | argument_expression_list ',' assignment_expression { $1->PushBack($3); $$=$1; }
	;

unary_expression
	: postfix_expression {$$=$1;}
	;

cast_expression
	: unary_expression {$$=$1;}
	;

multiplicative_expression
	: cast_expression {$$=$1;}
	| multiplicative_expression '*' cast_expression {$$ = new Multiplication($1, $3);}
	| multiplicative_expression '/' cast_expression {$$ = new Division($1, $3);}
	| multiplicative_expression '%' cast_expression {$$ = new Modulus($1, $3);}
	;

additive_expression
	: multiplicative_expression {$$=$1;}
	| additive_expression '+' multiplicative_expression {$$ = new Addition($1, $3);}
	| additive_expression '-' multiplicative_expression {$$ = new Subtraction($1, $3);}
	;

shift_expression
	: additive_expression {$$=$1;}
	| shift_expression LEFT_OP additive_expression  {$$ = new LShift($1, $3);}
	| shift_expression RIGHT_OP additive_expression {$$ = new RShift($1, $3);}
	;

relational_expression
	: shift_expression {$$=$1;}
	| relational_expression '<' shift_expression {$$ = new LessThan($1, $3);}
	| relational_expression '>' shift_expression {$$ = new GreaterThan($1, $3);}
	| relational_expression LE_OP shift_expression {$$ = new LessThanEQ($1, $3);}
	| relational_expression GE_OP shift_expression {$$ = new GreaterThanEQ($1, $3);}
	;

equality_expression
	: relational_expression {$$=$1;}
	| equality_expression EQ_OP relational_expression {$$ = new Equal($1, $3);}
	| equality_expression NE_OP relational_expression {$$ = new NotEqual($1, $3);}
	;

and_expression
	: equality_expression {$$=$1;}
	| and_expression '&' equality_expression {$$ = new BitwiseAND($1, $3);}
	;

exclusive_or_expression
	: and_expression {$$=$1;}
	| exclusive_or_expression '^' and_expression {$$ = new BitwiseXOR($1, $3);}
	;

inclusive_or_expression
	: exclusive_or_expression {$$=$1;}
	| inclusive_or_expression '|' exclusive_or_expression {$$ = new BitwiseOR($1, $3);}
	;

logical_and_expression
	: inclusive_or_expression {$$=$1;}
	| logical_and_expression AND_OP inclusive_or_expression {$$ = new LogicalAND($1, $3);}
	;

logical_or_expression
	: logical_and_expression {$$=$1;}
	| logical_or_expression OR_OP logical_and_expression {$$ = new LogicalOR($1, $3);}
	;


conditional_expression
	: logical_or_expression {$$=$1;}
    | logical_or_expression '?' expression ':' conditional_expression { $$ = new selectionStatement($1, $3, $5);}
	;

assignment_expression
	: conditional_expression {$$=$1;}
    | unary_expression '=' assignment_expression {$$ = new assignmentExpression($1, $3);}
	| unary_expression MUL_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new Multiplication($1, $3));}
	| unary_expression DIV_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new Division($1, $3));}
	| unary_expression MOD_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new Modulus($1, $3));}
	| unary_expression ADD_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new Addition($1, $3));}
	| unary_expression SUB_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new Subtraction($1, $3));}
	| unary_expression LEFT_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new LShift($1, $3));}
	| unary_expression RIGHT_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new RShift($1, $3));}
	| unary_expression AND_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new BitwiseAND($1, $3));}
	| unary_expression XOR_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new BitwiseXOR($1, $3));}
	| unary_expression OR_ASSIGN assignment_expression {$$ = new assignmentExpression($1, new BitwiseOR($1, $3));}
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression {$$=$1;}
	;

constant_expression
	: conditional_expression {$$=$1;}
	;

%%

Node *g_root;

Node *ParseAST(std::string file_name)
{
  yyin = fopen(file_name.c_str(), "r");
  if(yyin == NULL){
    std::cerr << "Couldn't open input file: " << file_name << std::endl;
    exit(1);
  }
  g_root = nullptr;
  yyparse();
  return g_root;
}
