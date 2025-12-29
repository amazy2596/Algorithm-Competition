%{
#include "parser.tab.h"
#include <stdio.h>
void yyerror(const char *s);
%}

%%
"i"     { return ID; }
"+"     { return ADD; }
"*"     { return MUL; }
"("     { return LPAREN; }
")"     { return RPAREN; }
"#"     { return 0; }  /* # 作为输入结束标志，返回 0 触发 yyparse 完成 */
[ \t\n] { /* 忽略空白符 */ }
.       { return yytext[0]; } /* 返回非法字符供语法分析报错 */
%%

int yywrap() {
    return 1;
}