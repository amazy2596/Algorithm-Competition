%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token ID ADD MUL LPAREN RPAREN

/* 定义优先级，解决潜在冲突（虽然本文法结构清晰，但定义优先级是好习惯） */
%left ADD
%left MUL

%%

/* 开始符号 */
input:
    expr { printf("结果：句子合法\n"); }
    ;

expr:
    expr ADD term
    | term
    ;

term:
    term MUL factor
    | factor
    ;

factor:
    LPAREN expr RPAREN
    | ID
    ;

%%

int main() {
    printf("请输入句子 (以 # 结束): ");
    /* 调用语法分析入口 */
    if (yyparse() == 0) {
        /* yyparse 返回 0 表示分析成功，但由于我们在规则中打印了，此处可留空或做收尾 */
    }
    return 0;
}

/* 错误处理函数 */
void yyerror(const char *s) {
    printf("结果：句子不合法 (原因: %s)\n", s);
}