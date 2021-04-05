%{
#include<stdio.h>
#include<string.h>
%}

%%
^""[a-z] { fprintf(yyout,"%c", yytext[0] - 'a' + 'A');}
". "[a-z] { fprintf(yyout,". %c", yytext[2] - 'a' + 'A');}
". "[A-Z] { fprintf(yyout,"%s", yytext);}

"."[a-z] { fprintf(yyout,".%c", yytext[1] - 'a' + 'A');}
"."[A-Z] { fprintf(yyout,"%s", yytext);}

[A-Z] { fprintf(yyout,"%c", yytext[0] - 'A' + 'a');}
. { fprintf(yyout,"%s",yytext);}
%%


int yywrap(){
	return 1;
}


int main(){
    extern FILE *yyin, *yyout;

    printf("Reading input from file input_b.txt\n");
    yyin=fopen("input_b.txt","r");
	yyout=fopen("output_b.txt","w");
    printf("Output is in file output_b.txt\n");

	yylex();
}
