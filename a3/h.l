%{
#include<string.h>
void check(char *);
%}


%%
[a-zA-Z]+ {check(yytext);printf("\nEnter word that you wish to search in file: ");}
. ;
\n ;
%%


int main(){
    printf("NOTE: Press ctrl d to exit\n");
    printf("Enter word that you wish to search in file input_h.txt: ");
	yylex();
	return 0;
}
void check(char *str){

	FILE *fp;
	char temp[30];
	
	
	
	fp=fopen("input_h.txt", "r");
	while((fscanf(fp, "%s", temp))!=EOF)
	{
		if(!(strcmp(temp, str)))
		{
			printf("FOUND\n");
			return;
		}
		
	}
	printf("NOT FOUND\n");
		return;
}
