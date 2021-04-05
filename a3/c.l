%{
int n = 0 ;
%}


%%

[//](.*) printf("here\n");

[/*]((.|\n)*)[*/] ;

["]([^"]*)["] {n++;printf("%s\n", yytext);}

"while"|"if"|"else" {n++;printf("%s\n", yytext);}


"int"|"float" {n++;printf("%s\n", yytext);}


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
    
	yylex();
	
	printf("\ntotal no. of token = %d\n", n);
}
