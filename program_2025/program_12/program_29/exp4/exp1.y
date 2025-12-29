%{
#include <stdio.h>
#include <ctype.h>
int yylex();
void yyerror(const char *s);
%}

%token ID
%left '+' '-'
%left '*' '/'
%right UMINUS 

%%
lines:  lines expr '\n' { printf("\n"); }
     |  lines '\n'
     |  /* empty */
     ;

expr:   expr '+' expr   { printf("+ "); }
    |   expr '-' expr   { printf("- "); }
    |   expr '*' expr   { printf("* "); }
    |   expr '/' expr   { printf("/ "); }
    |   '(' expr ')'
    |   '-' expr %prec UMINUS { printf("NEG "); }
    |   ID              { /* ID在词法分析中已打印或此处不处理，假设直接输出值 */ } 
    ;
%%

int yylex() {
    int c;
    while ((c = getchar()) == ' ' || c == '\t');
    if (isdigit(c) || isalpha(c)) {
        printf("%c ", c); // 读到操作数直接输出
        return ID;
    }
    return c;
}

int main() { return yyparse(); }
void yyerror(const char *s) { fprintf(stderr, "%s\n", s); }
int yywrap() { return 1; }