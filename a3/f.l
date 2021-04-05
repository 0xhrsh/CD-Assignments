%{
#include<stdio.h>
#include<string.h>
int counter = 0;
%}


%%
[a-zA-Z]+ { int len=strlen(yytext);if(len<10 && len>5) {counter++;}}

. ;

"\n" {printf("Number of words with length > 5 and < 10 are: %d\n", counter); return 0;}
%%

int yywrap(void){}

int main(){
	printf("Enter the sentence: ");
	yylex();

	return 0;
}
