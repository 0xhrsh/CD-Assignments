#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define repp(i,n) for(int i=0;i<n;i++)

void push(char *,int *,char);
void isproduct(char,char);
int ister(char);
int isnter(char);
int isstate(char);
void error();
void isreduce(char,char);
char pop(char *,int *);
void printt(char *,int *,char [],int);
void rep(char [],int);

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
    {"-1","j","d"},
    {"-1","-1","k"},
    {"-1","-1","-1"},
    {"-1","-1","-1"},
};

char ter[6]={'i','+','*',')','(','$'};
char nter[3]={'E','T','F'};
char states[12]={'a','b','c','d','e','f','g','h','m','j','k','l'};
char stack[100];
int top=-1;
char temp[10];

struct grammar{
    char left;
    char right[5];
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

    char inp[80],x,p,dl[80],y,bl='a';
    int i=0,j,k,l,n,m,c,len;

    printf("Enter the input :");
    scanf("%s",inp);

    len=strlen(inp);
    inp[len]='$';
    inp[len+1]='\0';
    push(stack,&top,bl);
    printf("\nStack \t\t\tInput");
    printt(stack,&top,inp,i);

    do{
        x=inp[i];

        p=stack[top];
        isproduct(x,p);

        if(strcmp(temp,"-1")==0)
            error();

        if(strcmp(temp,"acc")==0)
            break;
        else{
            if(temp[0]=='s'){
                push(stack,&top,inp[i]);
                push(stack,&top,temp[1]);
                i++;
            }else{
                if(temp[0]=='r'){
                    j=isstate(temp[1]);

                    strcpy(temp,rl[j-2].right);
                    dl[0]=rl[j-2].left;
                    dl[1]='\0';

                    n=strlen(temp);

                    repp(k,2*n)
                        pop(stack,&top);

                    for(m=0;dl[m]!='\0';m++)
                        push(stack,&top,dl[m]);

                    l=top;
                    y=stack[l-1];
                    isreduce(y,dl[0]);

                    for(m=0;temp[m]!='\0';m++)
                        push(stack,&top,temp[m]);
                }
            }
        }

    printt(stack,&top,inp,i);
    }while(inp[i]!='\0');

    if(strcmp(temp,"acc")==0)
        printf(" \nInput accepted");
    else
    printf(" \nInput not accepted.");
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

int isnter(char x){
    repp(i,3)
        if(x==nter[i])
            return i+1;

    return 0;
}

int isstate(char p){
    repp(i, 12)
        if(p==states[i])
            return i+1;

    return 0;
}

void error(){
    printf("Error in the input ");
    exit(0);
}

void isreduce(char x,char p){
    int k=isstate(x);
    int l=isnter(p);

    strcpy(temp,G[k-1].r[l-1]);
}


char pop(char *s,int *sp){
    char item;

    if(*sp==-1)
        printf("Stack is empty ");
    else{
        item=s[*sp];
        *sp=*sp-1;
    }

    return item;
}

void printt(char *t,int *p,char inp[],int i){
    int r;

    printf("\n");

    repp(r,*p+1)
        rep(t,r);

    printf("\t\t\t");

    for(r=i;inp[r]!='\0';r++)
        printf("%c",inp[r]);
}

void rep(char t[],int r){
    repp(i, 12){
        if(states[i] == t[r]){
            printf("%d", i);
            return;
        }
    }
    printf("%c",t[r]);
}