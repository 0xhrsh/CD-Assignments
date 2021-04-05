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

// driver code
int main(){
    extern FILE *yyin, *yyout;
    yyin=fopen("input_t.txt","r");
	yyout=fopen("output_t.txt","w");

	yylex();
	
	return 0;
}
