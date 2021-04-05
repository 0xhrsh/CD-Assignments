%{
int pno = 0, nno = 0;
%}

%%
[ ] ;

\+?[1-9][0-9]*			 {pno++; printf("Positive number: %s\n", yytext);}
-[1-9][0-9]*			 {nno++; printf("Negative number: %s\n", yytext);}

\+?0\.[0]*[1-9]+[0-9]*   {pno++; printf("Positive number: %s\n", yytext);}
-0\.[0]*[1-9]+[0-9]*	 {nno++; printf("Negative number: %s\n", yytext);}

\+?[1-9]+\.[0-9]+ {pno++; printf("Positive number: %s\n", yytext);}
-[1-9]+\.[0-9]+	 {nno++; printf("Negative number: %s\n", yytext);}

\n return 0;
. ;


%%


int yywrap(){}
int main(){
printf("Enter the numbers, space seperated: \n");
yylex();
printf ("\nnumber of positive numbers = %d\nnumber of negative numbers = %d\n", pno, nno);

return 0;
}
