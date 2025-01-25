%{
#include <stdio.h>
#include <string.h>
%}

%option noyywrap

/* Declare variables to track word count */
%{
int total_count = 0;
char target_word[100];
%}

%%

[a-zA-Z]+ {
    if (strcmp(yytext, target_word) == 0) {
        total_count++;
    }
}

.|\n    { }

<<EOF>> {
    printf("Frequency of '%s': %d\n", target_word, total_count);
    return 0;
}

%%

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <word> <filename>\n", argv[0]);
        return 1;
    }

    /* Copy target word */
    strcpy(target_word, argv[1]);

    /* Open input file */
    yyin = fopen(argv[2], "r");
    if (!yyin) {
        perror("Error opening file");
        return 1;
    }

    /* Begin scanning */
    yylex();

    fclose(yyin);
    return 0;
}