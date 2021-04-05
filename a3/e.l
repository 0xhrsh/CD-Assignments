%{
#include<stdio.h>
#include<string.h>
int i = 0;
%}


%%
([a-zA-Z])* {i++;} 

. ;

"\n" {printf("Number of words are: %d\n", i); return 0;}
%%

int yywrap(void){}

int main(){
	printf("Enter the sentence: ")
	yylex();

	return 0;
}
