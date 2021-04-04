%{
    #include <stdio.h>
    int counter = 0;
%}


%% 
" "[a-zA-Z]+" " {
    if (yyleng - 2 > counter) {
    	counter = yyleng - 2;
    }
}

[a-zA-Z]+" " {
    if (yyleng - 1 > counter) {
    	counter = yyleng - 1;
    }
}


[" "][a-zA-Z]+[".\n"] {
    if (yyleng - 3 > counter) {
    	counter = yyleng - 3;
        return 0;
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
