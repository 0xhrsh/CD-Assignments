%{
#include <string.h>
void checkPhoneNumber(char*);
%}


%%
[0-9]+	{checkPhoneNumber(yytext);return 0;}
%%

// driver code
int main(){
    printf("Enter the phone number: ");
	yylex();
	
	return 0;
}

void checkPhoneNumber(char* a){
    if(strlen(a) == 10 && a[0] != '0')
        printf("%s is a valid number\n", a);
    else
        printf("%s is not a valid number\n", a);
}