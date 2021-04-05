%{
#include <string.h>
%}


%%
(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\n	{printf("%s is a valid IP\n", yytext); return 0;}
. {printf("Invalid IP\n");return 0;}
\n return 0;
%%

// driver code
int main(){
    printf("Enter the IP: ");
	yylex();
	
	return 0;
}
