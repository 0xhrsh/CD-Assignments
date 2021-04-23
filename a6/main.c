#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


#define repp(i,n) for(int i=0;i<n;i++)
#define nl printf("\n");
#define tb printf("\t");

void push(char *,int *,char);
void isproduct(char,char);
int ister(char);
int isnter(char);
int isstate(char);
void isreduce(char,char);
char pop(char *,int *);
void printt(char *,int *,char [],int);

struct action{
    char row[6][5];
};

const struct action A[12]={
    {"sf","-1","-1","se","-1","-1"},
    {"-1","sg","-1","-1","-1","acc"},
    {"-1","rc","sh","-1","rc","rc"},
    {"-1","re","re","-1","re","re"},
    {"sf","-1","-1","se","-1","-1"},
    {"-1","rg","rg","-1","rg","rg"},
    {"sf","-1","-1","se","-1","-1"},
    {"sf","-1","-1","se","-1","-1"},
    {"-1","sg","-1","-1","sl","-1"},
    {"-1","rb","sh","-1","rb","rb"},
    {"-1","rb","rd","-1","rd","rd"},
    {"-1","rf","rf","-1","rf","rf"}
};

struct gotol{
    char r[3][4];
};

const struct gotol G[12]={
    {"b","c","d"},
    {"-1","-1","-1"},
    {"-1","-1","-1"},
    {"-1","-1","-1"},
    {"i","c","d"},
    {"-1","-1","-1"},
    {"-1","k","d"},
    {"-1","-1","l"},
    {"-1","-1","-1"},
    {"-1","-1","-1"},
};

char ter[6]={'i','+','*',')','(','$'};
char nter[3]={'E','T','F'};
char states[12]={'a','b','c','d','e','f','g','h','j','k','l','m'};
char stack[100];
int top=-1;
char temp[10];

struct grammar{
    char left;
    char right[10];
};

const struct grammar rl[6]={
    {'E',"e+T"},
    {'E',"T"},
    {'T',"T*F"},
    {'T',"F"},
    {'F',"(E)"},
    {'F',"i"},
};

void main(){

    char inp[100],dl[80];

    printf("Enter the input :");
    scanf("%s",inp);

    int len=strlen(inp);
    inp[len]='$';
    inp[len+1]='\0';

    push(stack,&top,'a');

    printf("\nStack \t\t\tInput\n");
    printt(stack,&top,inp,0);

    int i = 0;
    do{
        isproduct(inp[i],stack[top]);

        if(strcmp(temp,"-1")==0){
            printf("Error in the input");
            exit(1);
        }

        if(strcmp(temp,"acc")==0)
            break;
        else if(temp[0]=='s'){    
            push(stack,&top,inp[i]);
            push(stack,&top,temp[1]);
            i++;
        }else if(temp[0]=='r'){
            int j=isstate(temp[1]);
            strcpy(temp,rl[j-2].right);
            dl[0]=rl[j-2].left;
            dl[1]='\0';

            repp(k,2*strlen(temp))
                pop(stack,&top);

            for(int m=0;dl[m]!='\0';m++)
                push(stack,&top,dl[m]);

            isreduce(stack[top-1],dl[0]);

            for(int m=0;temp[m]!='\0';m++)
                push(stack,&top,temp[m]);
        }nl;
        printt(stack,&top,inp,i);
    }while(inp[i]!='\0');

    nl;
    if(strcmp(temp,"acc")==0)
        printf("Input accepted");
    else
        printf("Input not accepted.");
}

void push(char *s,int *sp,char item){
    if(*sp==100)
        printf("Stack is full ");
    else{
        *sp=*sp+1;
        s[*sp]=item;
    }
}

void isproduct(char x,char p){
    int k=ister(x);
    int l=isstate(p);

    strcpy(temp,A[l-1].row[k-1]);
}

int ister(char x){
    repp(i,6)
        if(x==ter[i])
            return i+1;
    return 0;
}

int isstate(char p){
    repp(i, 12)
        if(p==states[i])
            return i+1;
    return 0;
}

int isnter(char x){
    repp(i,3)
        if(x==nter[i])
            return i+1;

    return 0;
}


void isreduce(char x,char p){
    int k=isstate(x);
    int l=isnter(p);

    strcpy(temp,G[k-1].r[l-1]);
}


char pop(char *s,int *sp){
    if(*sp!=-1){
        *sp=*sp-1;
        return s[*sp+1];
    }
    printf("Stack is empty ");
    return '\0';
}

void printt(char *t,int *p,char inp[],int i){
    repp(r,*p+1){
        bool p_flag = true;
        repp(ii, 12){
            if(states[ii] == t[r]){
                printf("%d", ii);
                p_flag = false;
                break;
            }
        }
        if(p_flag)
            printf("%c",t[r]);
    }
    tb;tb;tb;

    printf("%s", inp+i);
}
