#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define mem(v,i) memset(v,i,sizeof(v))
#define MAX_STATES 1000
#define nl printf("\n")
#define STAR_LINE printf("\n\n***************************\n")
#define DASH_LINE printf("-----------------------\n")


int main(){

    // Input
    int n,s, start_state, n_end_states;
    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the start state (0 indexed): ");
    scanf("%d", &start_state);

    printf("Enter the number of end states: ");
    scanf("%d", &n_end_states);

    int end_states[n_end_states];
    
    printf("Enter the end states (space seperated) (0 indexed): ");
    for(int i = 0; i < n_end_states; i++){
        scanf("%d", &end_states[i]);
    }

    printf("Enter the number of symbols (excluding ε): ");
    scanf("%d", &s);

    int symbols[s];
    printf("Enter the characters for symbols (space seperated) [excluding ε]:");
    for(int i = 0; i < s; i++){
        getchar();
        symbols[i] = getchar();
    }
    

    bool transitions[n][s][n];
    bool closure[n][n];
    mem(transitions, 0);
    mem(closure, 0);

    printf("Enter the transitions states for the given symbol:\n\n");
    printf("Make sure the states are space seperated and add -1 after entering all states\n");
    printf("Example 2 3 -1\n\n");

    for(int i = 0; i < n; i++){
        int inp;
        for(int j = 0; j < s; j++){

            printf("transitions of state %d for symbol %c (0 indexed):", i, symbols[j]);

            scanf("%d", &inp);
            while(inp != -1){
                transitions[i][j][inp] = true;
                scanf("%d", &inp);
            }
        }
        printf("transitions of state %d for symbol ε (0 indexed):", i);
        
        scanf("%d", &inp);
        while(inp != -1){
            closure[i][inp] = true;
            scanf("%d", &inp);
        }
        closure[i][i] = true;
        nl;
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }

    // Uncomment to check input
    // for(int i = 0; i < n; i++){
    //     printf("For state %d:\n", i);
    //     for(int j = 0; j < s; j++){
    //         for(int k = 0; k < n; k++){
    //             printf("%d ",transitions[i][j][k]);
    //         }nl;
    //     }
    //     for(int j = 0; j < n; j++)
    //         printf("%d ",closure[i][j]);
    //     nl;nl;
    // }

    int n_dfa_states = 1;

    bool dfa_state_matching[MAX_STATES][n];
    mem(dfa_state_matching, 0);

    bool dfa_table[MAX_STATES][s][MAX_STATES];
    mem(dfa_table, 0);

    int q[100000];
    int qstart = 0;
    int qend = 0;

    // Put the start state in the queue
    q[qstart] = 0;
    qend++;
    for(int i = 0; i < n; i++){
        dfa_state_matching[0][i] = closure[start_state][i];   
    }
    
    // take a dfs_state from the queue
    while(qstart<qend){
        int curr_dfa_state = q[qstart++];

        // for each symbol
        for(int j=0; j < s; j++){
            bool reachable_states[n];
            mem(reachable_states, 0);
            // for each state true in dfa_state_matching[curr_dfa_state]
            for(int i = 0; i < n; i++){
                if(dfa_state_matching[curr_dfa_state][i]){
                    // add the reachable states to a boolean array  
                    for(int k = 0; k < n; k++){
                        if(transitions[i][j][k])
                            reachable_states[k] = true;
                    }
                }
            }

            // Get the coverage of that boolean array
            for(int i = 0; i < n; i++){
                if(reachable_states[i]){
                    for(int k = 0; k < n; k++){
                        if(closure[i][k]){
                            reachable_states[k] = true;
                        }
                        
                        
                    }
                }   
            }

            // Uncomment to check reachability
            // printf("For current state %d and symbol %c, the reachable states are:", curr_dfa_state, symbols[j]);
            // for(int k = 0; k < n; k++)
            //     if(reachable_states[k])
            //         printf("%d ", k);
            // nl;


            // if that bool array is not already present in the matching
                // add it to the matching table and put it in the queue
            bool present = false;
            int new_state;

            for(int i = 0; i < n_dfa_states; i++){
                bool isSame = true;
                for(int k = 0; k < n; k++){
                    if(dfa_state_matching[i][k]!=reachable_states[k]){
                        isSame = false;
                        break;
                    }
                }
                if(isSame){
                    present = true;
                    new_state = i;
                    break;
                }
            }

            if(present){
                dfa_table[curr_dfa_state][j][new_state] = true;
            } else{
                new_state = n_dfa_states;

                for(int i = 0; i < n; i++)
                    dfa_state_matching[new_state][i] = reachable_states[i];

                dfa_table[curr_dfa_state][j][new_state] = true;
                n_dfa_states++;

                // add new_state to queue
                q[qend] = new_state;
                qend++;
                
            }
        }
    }

    STAR_LINE;
    printf("STATES");
    for(int i = 0; i < s; i++)printf("\t\t %c", symbols[i]);
    nl;
    DASH_LINE;
    // print stuff here
    for(int i = 0; i < n_dfa_states; i++){
        for(int j = 0; j < n; j++){
            if(dfa_state_matching[i][j]){
                printf("%d", j);
            }
        }
        printf("\t\t");
        for(int j = 0; j < s; j++){
            for(int k = 0; k < n_dfa_states; k++){
                if(dfa_table[i][j][k]){
                    
                    for(int l = 0; l < n; l++){
                        if(dfa_state_matching[k][l])
                            printf("%d", l);
                    }
                    
                }
            }
            printf("\t\t");
        }
        printf("\n");
    }

    return 0;
}