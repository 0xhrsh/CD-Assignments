#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATE 100
#define MAX_SYMBOLS 2


#define mem(v,i) memset(v,i,sizeof(v)) //Use mem(v,60) to initialize with 10^9
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repp(i,n) for(int i=(0);i<(n);i++)
#define repr(i,n) for(int i=(n);i>=0;i--)
#define repl(i,a,b) for(ll i=(a);i<(b);i++)

#define line printf("\n===========================\n")
#define nl printf("\n");

int main(){
    int n, s;

    printf("Enter number of states");
    scanf("%d", &n);

    printf("Enter number of symbols");
    scanf("%d", &s);

    int start_state;
    printf("Enter start state");
    scanf("%d", &start_state);

    int n_end;
    printf("Enter number of final states");
    scanf("%d", &n_end);

    bool end[n];
    mem(end, 0);
    printf("Enter %d final states (Space seperated):", n_end);
    repp(i, n_end){
        int ts;
        scanf("%d", &ts);
        end[ts] = true;
    }


    int dfa[n][s];

    repp(i,n){
        repp(j,s){
            printf("Enter the index of the state reached for %d with symbol %d (enter -1 if no state is reached)", i, j);
            scanf("%d", &dfa[i][j]);
        }
    }

    bool isSame[n][n];
    mem(isSame, 0);

    int counted[n];
    repp(i, n)counted[i] = -1;
    

    repp(i, n){
        rep(j,i+1, n){
            if(counted[j] != -1)continue;
            bool same = true;
            repp(k, s){
                if(dfa[i][k] != dfa[j][k]){
                    same = false;
                    if((dfa[i][k] == j && dfa[j][k] == i)){
                        same = true;
                    } else{
                        break;
                    }
                    
                }
                if(same){
                    isSame[i][j] = true;
                    counted[j] = i;
                }
            }
        }
    }

    line;
    printf("States of minimised DFA:\t");
    repp(i, n){
        if(counted[i] != -1) continue;
        printf("%d", i);
        repp(j, n){
            if(isSame[i][j])printf("%d", j);
        }
        printf(" ");
    }
        

    line;

    printf("DFA Table:\n");
    
    printf("STATE");
    repp(j,s)printf("\t\t%d", j);
    nl;

    repp(i, n){
        if(counted[i] != -1)continue;

        printf("%d", i);
        repp(j, n){
            if(isSame[i][j])printf("%d", j);
        }
        printf(":");

        repp(j, s){
            if(dfa[i][j] == -1){
                printf("\t\t-1");
            } else {
                if (counted[dfa[i][j]] == -1){
                    printf("\t\t%d", dfa[i][j]);
                    repp(k, n){
                        if(isSame[dfa[i][j]][k])printf("%d", k);
                    }
                }
                else{
                    int tv = counted[dfa[i][j]];
                    printf("\t\t%d", tv);
                    repp(k, n){
                        if(isSame[tv][k])printf("%d", k);
                    }
                }
            }
                
                
        }
        nl;
    }
}