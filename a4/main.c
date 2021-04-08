#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SMBLS 50
#define mem(v, k) memset(v, k, sizeof(v))
#define PIPE -2
#define EPSILON -3

#define repp(i,n) for(int i = 0; i < n; i++)

char smbls[MAX_SMBLS + 1][20];
int productions[MAX_SMBLS + 1][(MAX_SMBLS * 2) + 1];
int count, n;
bool firstFound[MAX_SMBLS + 1];
bool first[MAX_SMBLS + 1][MAX_SMBLS + 1];

void getFirst(int smbl){
    if(firstFound[smbl])return;

    repp(i, 2 * MAX_SMBLS){
        if(productions[smbl][i] == -1)break;

        if(i == 0 || productions[smbl][i-1] == PIPE){

            if(productions[smbl][i] < n){
                // it is a non-terminal smbl
                getFirst(productions[smbl][i]);
                repp(j, MAX_SMBLS){
                    first[smbl][j] = first[smbl][j] || first[productions[smbl][i]][j];
                }
                firstFound[smbl] = true;
            } else{
                first[smbl][productions[smbl][i]] = true;
                firstFound[smbl] = true;
            }
        }
    }
    return;
}


int main(){
    // init stuff
    count = 0;
    mem(firstFound, 0);
    mem(first, 0);
    repp(i, MAX_SMBLS){
        productions[i][0] = -1;
    }


    printf("Enter the number of productions: ");
    scanf("%d", &n);
    
    repp(i,n){
        printf("Enter %dth terminal symbol (string): ", i+1);
        scanf("%s", smbls[i]);
        count++;
    }
    
    strcpy(smbls[count++], "?");

    printf("Enter RHS of the following productions: \n");
    repp(i, n){
        printf("%s -> ", smbls[i]);
        char simp[250];
        getchar();
        scanf("%[^\n]", simp);
        
        char * temp;
        temp = strtok (simp," ");

        while (temp != NULL){
            

            if(temp[0] == '|'){
                // fprintf(stderr, "Pipe detected\n");
                repp(j, 2 * MAX_SMBLS){
                    if(productions[i][j] == -1){
                        productions[i][j] = PIPE;
                        productions[i][j + 1] = -1;
                        break;
                    }
                }
                temp = strtok(NULL, " ");
                continue;
            } 

            bool doesExists = false;
            repp(j,count){
                if(strcmp(smbls[j], temp)==0){
                    repp(k, 2 * MAX_SMBLS){ // put j in production[i]
                       if(productions[i][k] == -1){
                            productions[i][k] = j;
                            productions[i][k + 1] = -1;
                            break;
                        }
                    }
                    
                    doesExists = true;
                    break;
                }
            }
            if(!doesExists){
                // put count in production[i]
                strcpy(smbls[count],temp);
                repp(j, 2 * MAX_SMBLS){
                    if(productions[i][j] == -1){
                        productions[i][j] = count;
                        productions[i][j + 1] = -1;
                        break;
                    }
                }
                count++;
            }

            temp = strtok(NULL, " ");
            
            
        }
    }

    // // Uncomment to check if input is read correctly
    // repp(i, n){
    //     repp(j, MAX_SMBLS){
    //         if(productions[i][j] == -1) break;
    //         else if(productions[i][j] == PIPE) printf("| ");
    //         else if(productions[i][j] == EPSILON) printf("? ");
    //         else printf("%s ", smbls[productions[i][j]]);
    //     }
    //     printf("\n");
    // }

    printf("All Input done!\n\n");

    // Finding First 
    
    repp(i, n) // find first for each non terminal symbol
        getFirst(i);

    repp(i, n){ // Printing the first table
        printf("First(%s) = { ", smbls[i]);
        repp(j, MAX_SMBLS){
            if(first[i][j])printf("%s, ", smbls[j]);
        }
        printf("}\n");
    }


    // Finding Follow
    

    return 0;
}