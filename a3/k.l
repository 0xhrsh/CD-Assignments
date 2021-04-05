%{
	int postiveno=0;
	int negtiveno=0;
	int fractions=0;
%}


%%
\+?[1-9][0-9]*			 postiveno++;
-[1-9][0-9]*			 negtiveno++;

\+?0\.[0]*[1-9]+[0-9]* {fractions++;postiveno++;}
-0\.[0]*[1-9]+[0-9]*	 {fractions++;negtiveno++;}

\+?[1-9]+\.[0-9]+ {fractions++;postiveno++;}
-[1-9]+\.[0-9]+	 {fractions++;negtiveno++;}

\+?0.(0)+ fractions++;
-?0.(0)+ fractions++;

\n return 0;
. ;
%%

// driver code
int main(){
    printf("Enter the numbers (space seperated): \n");
	yylex();
	printf("\nNo. of positive numbers: %d", postiveno);
	printf("\nNo. of Negative numbers: %d", negtiveno);
	printf("\nNo. of numbers in fractions: %d\n", fractions);
	return 0;
}
