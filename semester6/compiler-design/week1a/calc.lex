%{
#include "calc.tab.h"
%}

%%

[0-9]+(\.[0-9]+)?  { yylval.num = atof(yytext); return NUMBER; }
"+"                { return PLUS; }
"-"                { return MINUS; }
"*"                { return MULTIPLY; }
"/"                { return DIVIDE; }
"^"                { return POWER; }
"("                { return '('; }
")"                { return ')'; }
\n                 { return NEWLINE; }
[ \t]              ; /* Ignore whitespace */
.                  { yyerror("Unknown character"); }

%%

int yywrap() {
    return 1;
}