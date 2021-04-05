%{
#include <math.h>
#include <string.h>
void checkPrime(char*);
%}


%%
[0-9]+	{checkPrime(yytext);return 0;}
%%

// driver code
int main(){
    printf("Enter the number (positive integer): ");
	yylex();
	return 0;
}

void checkPrime(char* a){
    
    long num = 0;
    for (int i = 0; i < strlen(a); i++)
        num = num * 10 + (a[i] - '0');
    
    int isPrime = 1;

    for (int i = 2; i <= sqrt(num); i++){
        if(num%i == 0){
            isPrime = 0;
            break;
        }
    }

    if(a[0] == '1' && strlen(a)==1)
        isPrime = 0;
  
    if (isPrime == 1)
        printf("%s is Prime!\n", a);
    else
        printf("%s is not Prime\n", a);
}