%{
#include <stdio.h>
#include <ctype.h>
%}

%%

[a-zA-Z_][a-zA-Z0-9_]*       { printf("Identifier: %s\n", yytext); } // Match identifiers
[0-9]+                        { printf("Number: %s\n", yytext); }    // Match numbers
[+\-*/=]                     { printf("Operator: %s\n", yytext); }  // Match operators
[{}()\[\],;]                { printf("Special Symbol: %s\n", yytext); } // Match special symbols
[ \t\n]+                     ;                                        // Ignore whitespace and newlines
.                            { printf("Unknown: %s\n", yytext); }    // Catch unknown tokens

%%

int main() {
    printf("Enter input to tokenize: \n");
    yylex(); // Start lexical analysis
    return 0;
}

int yywrap() {
    return 1; // Indicates end of input
}