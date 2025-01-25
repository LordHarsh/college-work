%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void yyerror(const char *s);
int yylex(void);
%}

%union {
    double num;
}

%token <num> NUMBER
%token PLUS MINUS MULTIPLY DIVIDE POWER
%token NEWLINE
%type <num> expr

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right POWER
%right UMINUS

%%

calclist: 
    | calclist expr NEWLINE { printf("Result: %g\n", $2); }
    ;

expr: NUMBER           { $$ = $1; }
    | expr PLUS expr   { $$ = $1 + $3; }
    | expr MINUS expr  { $$ = $1 - $3; }
    | expr MULTIPLY expr { $$ = $1 * $3; }
    | expr DIVIDE expr { 
        if ($3 == 0) {
            yyerror("Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3; 
        }
    }
    | expr POWER expr  { 
        $$ = pow($1, $3);
    }
    | MINUS expr %prec UMINUS { $$ = -$2; }
    | '(' expr ')'     { $$ = $2; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Simple Calculator\n");
    printf("Enter expressions (e.g., 2 + 3, 10 * (4 + 2), 2^3)\n");
    printf("Press Ctrl+D to exit\n");
    yyparse();
    return 0;
}