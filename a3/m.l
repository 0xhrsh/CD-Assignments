%{
#include <math.h>
#include <string.h>
void checkAmstrong(char*);
%}


%%
[0-9]+"\n"	{checkAmstrong(yytext);return 0;}
. {printf("Incorrect format, enter integer followed by enter\n"); return 0;}
%%

int main(){
    printf("Enter the number (press enter to submit): ");
	yylex();
	
	return 0;
}

void checkAmstrong(char* a){
    a[strlen(a)-1] = '\0';
    long num = 0;
    for (int i = 0; i < strlen(a); i++)
        num = num * 10 + (a[i] - '0');
    
    long  x = 0, y = 0, original_num = num;

    while (num > 0) {
        y = pow((num % 10), strlen(a));
        x = x + y;
        num = num / 10;
    }
  
    if (x == original_num)
        printf("%s is armstrong number \n", a);
    else
        printf("%s is not armstrong number\n", a);
}