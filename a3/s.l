%{
#include <string.h>
int lineCount = 0;
%}


%%
.*\n	{fprintf(yyout, "%d %s", ++lineCount,yytext);}
.*	{fprintf(yyout, "%d %s", ++lineCount,yytext); return 0;}
%%


int yywrap(){
	return 1;
}

// driver code
int main(){
    extern FILE *yyin, *yyout;
    yyin=fopen("input_s.txt","r");
	yyout=fopen("output_s.txt","w");

	yylex();
	
	return 0;
}
