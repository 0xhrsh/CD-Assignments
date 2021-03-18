#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DFA_MAX_STATES 1000

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


    bool transitions[n][s+1][n];

    for(int i = 0; i < n; i++){
        printf("Enter the transitions of state %d\n", i);
        int inp, k;
        for(int j = 0; j < s; j++){

            printf("\t Enter all reachable states for symbol %d (space seperated with last number -1)\n", j);
            if(j == 0){
                printf("\t Example 2 3 -1\n");
            }

            
            scanf("%d", &inp);
            k = 0;
            transitions[i][j][k++] = inp;
            while(inp != -1){
                transitions[i][j][inp] = true;
                scanf("%d", &inp);
            }
        }
        printf("\t Enter all reachable states for symbol ε (space seperated with last number -1)\n");
        
        scanf("%d", &inp);
        k = 0;
        transitions[i][s][k++] = inp;
        while(inp != -1){
            scanf("%d", &inp);
            transitions[i][s][k++] = inp;
        }

        print("\n");

    }

    // All input done


    // now make states with closures



    int n_dfa_states = 1;
    bool dfa_state_matching[DFA_MAX_STATES][n];
    int dfa_table[DFA_MAX_STATES][s][DFA_MAX_STATES];

    for(int i = 0; i < n; i++){
        dfa_state_matching[0][i] = transitions[start_state][s][i];
    }
    
    int q[100000];
    int qstart = 0;
    // Put the start state in the queue
    q[qstart] = 0;
    int qend = 1;    

    
    // take a dfs_state from the queue
    while(qstart<qend){
        int curr_dfa_state = q[qstart++];
        // for each symbol
        for(int j=0; j < s; j++){
            bool reachable_states[n];
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
                        reachable_states[k] = reachable_states[k] || transitions[i][s][k];
                    }
                }
            }


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
                dfa_table[curr_dfa_state][new_state][j] = true;
            } else{
                new_state = n_dfa_states;

                for(int i = 0; i < n; i++)
                    dfa_state_matching[new_state][i] = reachable_states[i];

                dfa_table[curr_dfa_state][new_state][j] = true;
                n_dfa_states++;

                // add new_state to queue
                q[qend] = new_state;
                qend++;
                
            }
        }
    }

    // print stuff here
    for(int i = 0; i < n_dfa_states; i++){
        for(int j = 0; j < n; j++){
            if(dfa_state_matching[i][j]){
                printf("%d ", j);
            }
        }
        printf(" || ");
        for(int j = 0; j < s; j++){
            for(int k = 0; k < n; k++){
                if(dfa_table[i][j][k]){
                    for(int l = 0; l < n; l++){
                        if(dfa_state_matching[k][l])
                            printf("%d", l);
                    }
                    printf(", ");
                }
            }
            printf(" | ");
        }
    }



    return 0;
}