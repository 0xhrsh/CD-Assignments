%{
#include <math.h>
#include <string.h>
void checkAmstrong(char*);
%}


%%
[0-9]+	{checkAmstrong(yytext);return 0;}
%%

// driver code
int main()
{
	yylex();
	
	return 0;
}

void checkAmstrong(char* a){
    
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