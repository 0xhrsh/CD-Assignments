%{
#include <string.h>
void checkEven(char*);
%}


%%
[0-9]+	{checkEven(yytext);return 0;}
%%

// driver code
int main(){
    printf("Enter the number (integer): ");
	yylex();
	
	return 0;
}

void checkEven(char* a){
    int num = a[strlen(a) - 1] - '0';

    if (num%2 == 0)
        printf("%s is Even\n", a);
    else
        printf("%s is Odd\n", a);
}