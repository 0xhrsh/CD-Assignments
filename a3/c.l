%{
int n = 0 ;
%}


%%

\/\/(.*)\n ;

"/*"[^*/]*"*/" ;

["]([^"]*)["] {n++;printf("%s\n", yytext);}

"do|while"|"if"|"else|switch|case" {n++;printf("%s\n", yytext);}


"int"|"float|char|string|bool|long|double" {n++;printf("%s\n", yytext);}


[a-zA-Z_][a-zA-Z0-9_]* {n++;printf("%s\n", yytext);}


"<="|"=="|"="|"++"|"-"|"*"|"+" {n++;printf("%s\n", yytext);}


[(){}|,;] {n++;printf("%s\n", yytext);}


[0-9]*"."[0-9]+ {n++;printf("%s\n", yytext);}


[0-9]+ {n++;printf("%s\n", yytext);}						

. ;

"\n" ;
%%


int main(){
	extern FILE *yyin;
    yyin=fopen("input_c.txt","r");
    
    printf("Reading from input_c.txt\n\n");
	yylex();
	
	printf("\ntotal no. of token = %d\n", n);
}
