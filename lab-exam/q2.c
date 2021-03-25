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

    int n_end;
    printf("Enter number of final states");
    scanf("%d", &n_end);

    int end[n_end];
    printf("Enter %d final states (Space seperated):", n_end);
    repp(i, n_end)scanf("%d", &end[i]);


    int dfa[n][s];

    repp(i,n){
        repp(j,s){
            printf("Enter the index of the state reached for %d with symbol %d (enter -1 if no state is reached)", i, j);
            scanf("%d", &dfa[i][j]);
        }
    }

    bool partitions[n][n];
    mem(partitions, 0);

    int ps[n];

    repp(i, n){
        partitions[1][i] = true;
        ps[i] = 1;
    }
    repp(i, n_end){
        partitions[1][end[i]] = false;
        partitions[0][end[i]] = true;
        ps[end[i]] = 0;
    }

    bool hasChanged = true;
    int k = 1;
    while(hasChanged){
        repp(i, n){
            if(partitions[k][i]){
                repp(j, n){
                    repp(si, s){
                        if(ps[dfa[i][si]] != ps[])
                    }
                }
            }
            
        }
    }

    return 0;
}
