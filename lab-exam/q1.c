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

    bool isVisited[n];
    mem(isVisited, 0);
    isVisited[start_state] = true;

    repp(i, n){
        repp(j, s){
            if(dfa[i][j] != -1){
                int k = dfa[i][j];
                isVisited[k] = true;
            }
        }
    }

    line;
    printf("States of minimised DFA:\t");
    for(int i = 0; i < n; i++)
        if(isVisited[i]==1)printf("%d ", i);

    line;

    printf("DFA Table:\n");
    
    printf("STATE");
    repp(j,s)printf("\t\t%d", j);
    nl;

    repp(i, n){
        if(isVisited[i]==0)continue;

        printf("%d:", i);

        repp(j, s){
            printf("\t\t%d",dfa[i][j]);
        }
        nl;
    }
}