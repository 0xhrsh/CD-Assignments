%{
#include<stdio.h>
int nc=0, nv=0;
%}


%%
[aeiouAEIOU] {nv++;}
[a-zA-Z] {nc++;}
. ;
"\n" return 0;
%%

int main(){
	printf("Enter the string, press enter (newline) to submit: ");
    yylex();
	
	printf("\nNo. of Consonants=%d\n", nc);
	printf("No. of Vowels=%d\n", nv);
}
