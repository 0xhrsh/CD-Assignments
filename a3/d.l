%{
#include<stdio.h>
int lc=0, sc=0, tc=0;
%}


%%
\n {printf(yytext);lc++;} //line counter
\t {printf(yytext);tc++;} //tab counter
([ ])+ {printf(yytext);sc++;} //space counter
. printf(yytext);
%%

int main()
{
 	extern FILE *yyin;
    yyin=fopen("input_d.txt","r");

    yylex();
	
	printf("\n\nNo. of lines=%d\n", lc);
	printf("No. of spaces=%d\n", sc);
	printf("No. of tabs=%d\n", tc);
	
}
