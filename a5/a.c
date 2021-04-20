#include<stdio.h>
#include<string.h>

#define repp(i,n) for(int i=0;i<n;i++)

void main(){
    int n;
    printf("Enter the number of non-terminal symbols: ");
    scanf("%d", &n);
    printf("\nNow enter %d productions:\n", n);

    char productions[100][50];
    int i=0;

    repp(p_no,n){
        char l[50],r[50],prod_part[10];
        int flag=0,consumed=0;
        printf("Enter the %dth production: ", p_no+1);
        scanf("%1s->%s",l,r);

        while(sscanf(r+consumed,"%[^|]s",prod_part) == 1 && consumed <= strlen(r)){
            if(prod_part[0] == l[0]){
                flag = 1;
            }
            consumed += strlen(prod_part)+1;
        }

        consumed = 0;
        while(sscanf(r+consumed,"%[^|]s",prod_part) == 1 && consumed <= strlen(r)){
            if(prod_part[0] == l[0]){
                sprintf(productions[i++],"%s'->%s%s'\0",l,prod_part+1,l);
            }
            else if(flag==1){
                sprintf(productions[i++],"%s->%s%s'\0",l,prod_part,l);
            }
            else{
                sprintf(productions[i++],"%s->%s\0",l,prod_part);
            }
            consumed += strlen(prod_part)+1;
        }

        if(flag == 1)  {
            sprintf(productions[i++],"%s'->ε\0",l);
        }
    }
    printf("\nProductions after removing left recursion:\n");
    repp(j, i)
        printf("%s\n",productions[j]);

    return;
}