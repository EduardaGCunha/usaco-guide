%{
#include <stdio.h>
%}
%%
[0-9]+  { printf("NUMBER"); }
"+"       { printf(" PLUS "); }
%%
int main(void) {
    yylex();
    return 0;
}
