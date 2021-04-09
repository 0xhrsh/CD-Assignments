#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SMBLS 50
#define mem(v, k) memset(v, k, sizeof(v))
#define PIPE -2
#define EPSILON n
#define DOLLAR dl
#define MAX_RULES 1000

#define repp(i,n) for(int i = 0; i < n; i++)

char smbls[MAX_SMBLS + 1][20];
int productions[MAX_SMBLS + 1][(MAX_SMBLS * 2) + 1];
int count, n, dl;
bool firstFound[MAX_SMBLS + 1], followFound[MAX_SMBLS + 1];
bool first[MAX_SMBLS + 1][MAX_SMBLS + 1], follow[MAX_SMBLS + 1][MAX_SMBLS + 1];

void getFirst(int smbl){
    if(firstFound[smbl])return;
    firstFound[smbl] = true;

    repp(i, 2 * MAX_SMBLS){
        if(productions[smbl][i] == -1)break;

        if(i == 0 || productions[smbl][i-1] == PIPE){
            if(productions[smbl][i] < n){ // it is a non-terminal smbl
                int Fsmbl = productions[smbl][i];
                while(Fsmbl != PIPE){
                    getFirst(Fsmbl);
                    if(Fsmbl < n){
                        repp(j, MAX_SMBLS){
                            if(j != EPSILON)
                            first[smbl][j] = first[smbl][j] || first[Fsmbl][j];
                        }
                    } else {
                        first[smbl][Fsmbl] = true;
                    }
                    if (first[Fsmbl][EPSILON]){
                        if(productions[smbl][i + 1] == PIPE || productions[smbl][i + 1] == -1)
                            first[smbl][EPSILON] = true;
                        Fsmbl = productions[smbl][++i];
                        if(Fsmbl == -1) return;

                    } else {
                        break;
                    }
                }
            } else{ // It is a terminal smbl
                first[smbl][productions[smbl][i]] = true;
            }
        }
    }
    return;
}

void getFollow(int smbl){
    if(followFound[smbl]) return;
    followFound[smbl] = true;

    repp(i, n){
        repp(j, MAX_SMBLS){
            if(productions[i][j] == -1) break;
                
            if(productions[i][j] == smbl){
                int Fsmbl = productions[i][j+1];
                while(j < MAX_SMBLS){
                    if (Fsmbl == -1 || Fsmbl == PIPE){
                        getFollow(i);
                        repp(k, MAX_SMBLS){
                            follow[smbl][k] = follow[smbl][k] || follow[i][k];
                        }
                        break;
                    } else if(Fsmbl < n){ // Non terminal
                        repp(k, MAX_SMBLS){
                            if(k != EPSILON)
                                follow[smbl][k] = follow[smbl][k] || first[Fsmbl][k];
                        }
                        if(first[Fsmbl][EPSILON]){
                            Fsmbl = productions[i][++j+1];
                            if(Fsmbl == -1 || Fsmbl == PIPE){
                                getFollow(i);
                                repp(k, MAX_SMBLS){
                                    follow[smbl][k] = follow[smbl][k] || follow[i][k];
                                }
                                break;
                            }
                        } else {
                            break;
                        }
                    } else { // Terminal
                        follow[smbl][Fsmbl] = true;
                        break;
                    }
                }  
                
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

    mem(followFound, 0);
    mem(follow, 0);
    
    repp(i, MAX_SMBLS){
        productions[i][0] = -1;
    }


    printf("Enter the number of non-terminal symbols: ");
    scanf("%d", &n);
    
    repp(i,n){
        printf("Enter %dth non-terminal symbol (string): ", i+1);
        scanf("%s", smbls[i]);
        count++;
    }
    
    strcpy(smbls[count++], "?");
    
    printf("\nPlease enter the RHS like CFG.\n");
    printf("For A -> d a | B C, you should enter: \"d a | B C\" only.\n");
    printf("See in1.txt and in2.txt for input for Grammar 1 and Grammar 2\n\n");

    printf("Enter RHS of the CGF for the following NT Symbols (everything should be space separated): \n");
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

    strcpy(smbls[count], "$");
    dl = count++;
    follow[0][dl] = true;

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
        printf("First(%s) =  ", smbls[i]);
        repp(j, MAX_SMBLS){
            if(first[i][j])printf("%s, ", smbls[j]);
        }
        printf("\n");
    }


    printf("\n\n");


    bool isDiff = true;
    while(isDiff){
        bool old_follow[n][MAX_SMBLS];
        repp(i,n){
            repp(j, MAX_SMBLS){
                old_follow[i][j] = follow[i][j];
            }
        }
        isDiff = false;

        mem(followFound, 0);
        repp(i, n) // Finding Follow
            getFollow(i);
        
        repp(i,n){
            repp(j, MAX_SMBLS){
                if(old_follow[i][j] != follow[i][j]){
                    isDiff = true;
                    break;
                } else {
                    isDiff = isDiff || isDiff;
                }
            }
            
        }
    }

    repp(i, n){ // Printing the first table
        printf("Follow(%s) =  ", smbls[i]);
        repp(j, MAX_SMBLS){
            if(follow[i][j])printf("%s, ", smbls[j]);
        }
        printf("\n");
    }

    // Printed the follow

    // Printing the predictive parsing table
    int table[n][MAX_SMBLS];
    mem(table, 0);

    int rules[MAX_RULES][3];
    int n_rules = 1;

    repp(i, n){
        
        bool flw[MAX_SMBLS];
        mem(flw, 0);
        int start = 0;
        int cdrg = true;;
        repp(j, MAX_SMBLS){
            int Fsmbl = productions[i][j];
            if(Fsmbl == -1){
                break;
            } else if(Fsmbl == PIPE){
                cdrg = true;
                mem(flw, 0);
                start = j+1;
            }else if (!cdrg){
                continue;
            }else if(Fsmbl >= n) {
                flw[Fsmbl] = true;
                cdrg = false;
            } else {
                repp(k, MAX_RULES) if(first[Fsmbl][k]) flw[k] = true;

                if(first[Fsmbl][EPSILON]){
                    if (productions[i][j+1] == PIPE || productions[i][j+1] == -1){
                        flw[EPSILON] = true;
                        cdrg = false;
                    }
                } else {
                    cdrg = false;
                }
            }
            if(!cdrg){
                rules[n_rules][0] = i;
                rules[n_rules][1] = start;
                rules[n_rules][2] = j;

                repp(k, MAX_SMBLS){
                    if(k!=EPSILON && flw[k]){
                        table[i][k] = n_rules;
                    }
                }

                if(flw[EPSILON]){
                   repp(k, MAX_SMBLS)
                    table[i][k] = follow[i][k]==true?n_rules:table[i][k];
                }
                n_rules++;
            }
        }
    }
    printf("\n\nParsing table (with rule nums) *find the rule num->rule matching at the bottom*\n");
    printf("\n\t");
    for(int i = n+1; i < count; i++){
        printf("%s\t", smbls[i]);
    }

    repp(i,n){
        printf("\n%s \t", smbls[i]);
        for(int j = n+1; j < count; j++){
            if(table[i][j]== 0) printf("err\t");
            else printf("%d \t", table[i][j]);
            
        }
    }

    printf("\n\nRules:\n");
    repp(i, n_rules){
        if(i==0)continue;
        printf("Rule %d:\t%s -> ", i, smbls[rules[i][0]]);
        int j = rules[i][1];
        while(true){
            if(productions[rules[i][0]][j] == PIPE || productions[rules[i][0]][j] == -1) 
                break;
            printf("%s ", smbls[productions[rules[i][0]][j]]);
            j++;
        }
        
        printf("\n");
    }



    return 0;
}