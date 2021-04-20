# include<stdio.h>
# include<string.h>

char input[100];

int i, l;

int T();
int E();
int EP();
int TP();
int F();

void main(){
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nE->TE'\nE'->+TE'|ɛ\nT->FT'\nT'->*FT'|ɛ\nF->(E)|id\n");
    printf("\nEnter the string to be checked: ");
    scanf("%s", input);
    // printf("String: %s\n", input);

    if(E()){
        if(input[i+1] == '\0'){
            printf("\nString \"%s\" is accepted!\n", input);
            return;
        }
    } 
    printf("\nString \"%s\" is not accepted!\n", input);
}

int E(){
    if(T()){
        if(EP()) return(1);
        return(0);
    }
    return(0);
}

int EP(){
    if(input[i] == '+'){
        i++;

        if(T()){
            if(EP())
                return(1);
            return(0);
        }
        return(0);
    }
    return(1);
}



int F(){
    if(input[i] == '('){
        i++;

        if(E()){
            if(input[i] == ')'){
                i++;
                return(1);
            }
            return(0);
        }
        return(0);
    } else if(input[i]=='i' && input[i+1] =='d'){ // checking for terminal symbols
        i+=2;
        return(1);
    }

    return(0);
}

int TP(){
    if(input[i] == '*'){
        i++;
        if(F()){
            if(TP())
                return(1);
            return(0);
        }
        return(0);
    }
    
    return(1);
}

int T(){
    if(F()){
        if(TP())
            return(1);
        return(0);
    }
    return(0);
}