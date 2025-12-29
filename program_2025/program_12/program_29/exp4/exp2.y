%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int yylex();
void yyerror(char *s);
%}

%token TRUE FALSE OR AND NOT LPAREN RPAREN
%left OR
%left AND
%right NOT

%%
input: /* empty */
     | input line
     ;

line: expr '\n' { printf("结果: %s\n", $1 ? "true" : "false"); }
    | '\n'      { /* 忽略空行 */ }
    ;

expr: expr OR expr  { $$ = $1 || $3; }
    | expr AND expr { $$ = $1 && $3; }
    | NOT expr      { $$ = !$2; }
    | LPAREN expr RPAREN { $$ = $2; }
    | TRUE          { $$ = 1; }
    | FALSE         { $$ = 0; }
    ;
%%

int yylex() {
    int c;
    
    /* 1. 跳过空格和制表符 */
    while ((c = getchar()) == ' ' || c == '\t');
    
    /* 2. 处理结束符和换行 */
    if (c == EOF) return 0;
    if (c == '\n') return '\n';
    
    /* 3. 识别关键字 */
    if (isalpha(c)) {
        char buf[32];
        int i = 0;
        
        do {
            if (i < 31) buf[i++] = c;
            c = getchar();
        } while (isalpha(c));
        
        buf[i] = '\0';
        ungetc(c, stdin); /* 吐回多读的字符 */
        
        if (strcmp(buf, "true") == 0) return TRUE;
        if (strcmp(buf, "false") == 0) return FALSE;
        if (strcmp(buf, "or") == 0) return OR;
        if (strcmp(buf, "and") == 0) return AND;
        if (strcmp(buf, "not") == 0) return NOT;
        
        return c; /* 未知单词 */
    }
    
    /* 4. 关键修复：将字符转换为 Token */
    if (c == '(') return LPAREN;
    if (c == ')') return RPAREN;
    
    /* 5. 其他字符 */
    return c;
}

int main() { 
    printf("请输入布尔表达式 (如 not (true or false)), 按回车查看结果 (Ctrl+D 退出):\n");
    return yyparse(); 
}

void yyerror(char *s) { 
    printf("Error: %s\n", s); 
}

int yywrap() { return 1; }