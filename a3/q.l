%{
    #include<stdio.h>    
    int isValid = 1;
%}

%% 
[a-z]+[a-z0-9._]*@[a-z]+(.[a-z]+)+ printf("%s is a valid email!\n", yytext); 

\n return 0;
. isValid = 0;
%%

int main(){
    printf("Enter Email: ");
    yylex();
    if(isValid == 0)printf("Invalid email.\n");
    return 0;
}