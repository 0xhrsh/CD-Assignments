%{
#include <string.h>
int lineCount = 0;
%}


%%
\"[^\"]*\" {fprintf(yyout, "%s", yytext);}
\'[^\']*\' fprintf(yyout, yytext);
\/\/(.*)\n ;
"/*"[^*/]*"*/" ;

%%


int yywrap(){
	return 1;
}


int main(){
    extern FILE *yyin, *yyout;

    printf("Reading from file input_t.txt\n");
    yyin=fopen("input_t.txt","r");
	yyout=fopen("output_t.txt","w");
    printf("Writing into file output_t.txt\n");

	yylex();
	
	return 0;
}
