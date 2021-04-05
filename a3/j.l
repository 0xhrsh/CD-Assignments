%{
#include<stdio.h>
#include<string.h>

char word [] = "word";
int count = 0;

%}


%%
[a-zA-Z]+ { if(strcmp(yytext, word)==0)count++;}
\n ;
. ;		
%%


int yywrap(){
	return 1;
}

int main(){
    extern FILE *yyin, *yyout;
    
    yyin=fopen("input_j.txt", "r");
    yylex();
    
    printf("Frequency of the word \"%s\" in the file input_j.txt is %d\n", word, count);
	
}
