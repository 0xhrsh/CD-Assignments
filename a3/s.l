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


int main(){
    extern FILE *yyin, *yyout;

    printf("Reading from file input_s.txt\n");
    yyin=fopen("input_s.txt","r");
	yyout=fopen("output_s.txt","w");
    printf("Writing into file output_s.txt\n");

	yylex();
	
	return 0;
}
