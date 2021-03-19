#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define mem(v,i) memset(v,i,sizeof(v))
#define MAX_STATES 1000
#define nl printf("\n")
#define STAR_LINE printf("\n\n*************************************\n")
#define DASH_LINE printf("-----------------------------------------\n")


int main(){

    // Input
    int n,s, start_state, n_end_states;
    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the names (should be integers) of states (space seperated): ");
    int state_names[n];
    int temp_var;
    for(int i = 0; i < n ; i++){
        scanf("%d", &state_names[i]);
    }


    printf("Enter the start state: ");
    scanf("%d", &temp_var);
    for(int tt = 0; tt < n; tt++)if(temp_var == state_names[tt])start_state = tt;

    printf("Enter the number of end states: ");
    scanf("%d", &n_end_states);

    int end_states[n_end_states];
    
    printf("Enter the end states (space seperated): ");
    for(int i = 0; i < n_end_states; i++){
        scanf("%d", &temp_var);
        for(int tt = 0; tt < n; tt++)if(temp_var == state_names[tt])end_states[i] = tt;
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
    printf("So if the transitions states are 2 and 3, you should enter: 2 3 -1\n");
    printf("In case there are no transitions states, just enter -1\n");

    for(int i = 0; i < n; i++){
        int inp;
        for(int j = 0; j < s; j++){

            printf("transitions of state %d for symbol %c:", state_names[i], symbols[j]);
            scanf("%d", &temp_var);
            while(temp_var != -1){
                for(int tt = 0; tt < n; tt++)if(temp_var == state_names[tt])inp = tt;
                // printf("\n==>%d %d \n",temp_var, inp);
                transitions[i][j][inp] = true;
                scanf("%d", &temp_var);
            }
        }
        printf("transitions of state %d for symbol ε:", state_names[i]);
        
        scanf("%d", &temp_var);
        while(temp_var != -1){
            for(int tt = 0; tt < n; tt++)if(temp_var == state_names[tt]){inp = tt;break;}
            closure[i][inp] = true;
            scanf("%d", &temp_var);
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
    //     printf("For state %d:\n", state_names[i]);
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
            //         printf("%d ", state_names[k]);
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
    printf("States for DFA:\t\t");
    for(int i = 0; i < n_dfa_states; i++){
        for(int j = 0; j < n ; j++){
            if(dfa_state_matching[i][j])printf("%d ",state_names[j]);
        }printf(", ");
    }
    nl;
    printf("Start State for DFA:\t");
    for(int j = 0; j < n ; j++){
        if(dfa_state_matching[0][j])printf("%d ",state_names[j]);
    }
    nl;
    printf("Final States for DFA:\t");
    for(int i = 0; i < n_dfa_states; i++){
        for(int j = 0; j < n_end_states ; j++){
            if(dfa_state_matching[i][end_states[j]]){
                for(int k = 0; k < n ; k++){
                    if(dfa_state_matching[i][k])printf("%d ",state_names[k]);
                }
                printf(", ");
                break;
            }
        }
    }
    nl;nl;nl;
    printf("STATES");
    for(int i = 0; i < s; i++)printf("\t\t %c", symbols[i]);
    nl;
    DASH_LINE;
    // print stuff here
    for(int i = 0; i < n_dfa_states; i++){
        for(int j = 0; j < n; j++){
            if(dfa_state_matching[i][j]){
                printf("%d", state_names[j]);
            }
        }
        printf("\t\t");
        for(int j = 0; j < s; j++){
            for(int k = 0; k < n_dfa_states; k++){
                if(dfa_table[i][j][k]){
                    for(int l = 0; l < n; l++){
                        if(dfa_state_matching[k][l])
                            printf("%d", state_names[l]);
                    }
                    
                }
            }
            printf("\t\t");
        }
        printf("\n");
    }

    return 0;
}