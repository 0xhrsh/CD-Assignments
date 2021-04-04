%{
#include<stdio.h>
int lc=0, sc=0, tc=0;
%}


%%
\n lc++; //line counter
\t tc++; //tab counter
([ ])+ sc++; //space counter
. ;
%%

int main()
{
	yylex();
	
	printf("No. of lines=%d\n", lc);
	printf("No. of spaces=%d\n", sc);
	printf("No. of tabs=%d\n", tc);
	
}
