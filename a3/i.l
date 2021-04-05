%{
    #include <stdio.h>
    int counter = 0;
%}


%% 
[a-zA-Z]*[^a-zA-Z \n]+[^ \n]* ;

[a-zA-Z]+ {
    if (yyleng > counter) {
    	counter = yyleng;
    }
}

"\n" return 0; 
. ;
%%

int main() {
    printf("Assumption: Words will be made up of alphabets and seperated by spaces.\nPress enter (newline) to get answer\n");
    yylex();
    printf("Largest word has length: %d", counter);
    printf("\n");
}
