%{
#include<stdio.h>
#include<string.h>
%}

%%
['\n'] { fprintf(yyout,"\n");}
(.*)	{ fprintf(yyout,"%s",yytext);}
%%


int yywrap(){
	return 1;
}


int main(){
    extern FILE *yyin, *yyout;

    printf("Reading input from file input_a.txt\n");
    yyin=fopen("input_a.txt","r");
	yyout=fopen("output_a.txt","w");
    printf("Output is in file output_a.txt\n");

	yylex();
}
