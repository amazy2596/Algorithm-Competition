%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* makeNode(char data, Node* l, Node* r) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data; n->left = l; n->right = r;
    return n;
}

void printTree(Node* root, int level) {
    if (!root) return;
    for(int i=0; i<level; i++) printf("  ");
    printf("%c\n", root->data);
    printTree(root->left, level+1);
    printTree(root->right, level+1);
}

int yylex();
void yyerror(const char *s);
%}

%union { char charVal; struct Node* nodeVal; }

%token <charVal> CHAR
%type <nodeVal> expr term factor atom

%%
line: expr '\n' { printf("Syntax Tree:\n"); printTree($1, 0); }
    | '\n'
    ;

/* 1. 表达式 (Expr) 处理选择运算 (|) */
expr: expr '|' term { $$ = makeNode('|', $1, $3); }
    | term          { $$ = $1; }
    ;

/* 2. 项 (Term) 处理连接运算 (implicit concatenation) */
term: term factor   { $$ = makeNode('.', $1, $2); }
    | factor        { $$ = $1; }
    ;

/* 3. 因子 (Factor) 处理闭包运算 (*) */
factor: atom '*'    { $$ = makeNode('*', $1, NULL); }
      | atom        { $$ = $1; }
      ;

/* 4. 原子 (Atom) 处理括号和字符 */
atom: '(' expr ')'  { $$ = $2; }
    | CHAR          { $$ = makeNode($1, NULL, NULL); }
    ;
%%

int yylex() {
    int c;
    while((c=getchar()) == ' ' || c=='\t'); 
    
    if (c == EOF) return 0;
    
    /* 字母和数字识别为 CHAR，其他符号直接返回 */
    if(isalnum(c)) { 
        yylval.charVal = c; 
        return CHAR; 
    }
    return c;
}

int main() { 
    printf("请输入正则表达式 (如 ab|c*), 按回车生成树 (Ctrl+D 退出):\n");
    yyparse(); 
    return 0; 
}

void yyerror(const char* s) { 
    printf("Error: %s\n", s); 
}

int yywrap() { return 1; }