%{
#include<string.h>
void doSearch(char *);
%}


%%
[a-zA-Z]*[^a-zA-Z \n]+[^ \n]* ;
[a-zA-Z]+ {doSearch(yytext);return 0;}
. ;
\n ;
%%


int main(){
    printf("Enter word that you wish to search in file input_h.txt: ");
	yylex();
	return 0;
}
void doSearch(char *str){

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
