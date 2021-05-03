#include <bits/stdc++.h>
using namespace std;

#define mem(v,i) memset(v,i,sizeof(v))

#define nl cout<<endl
#define el cerr<<endl

#define DASH_LINE cout<<"=====================================\n"

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repp(i,n) for(int i=(0);i<(n);i++)

#define MAX_LINE 20
#define MAX_VARS 256

#define DEF 1
#define USE 2

int main(){
    cout<<"Enter the number of basic blocks: ";
    int n;
    cin>>n;

    vector<string> blocks[n][MAX_LINE];
    int block_size[n];
    // int variables[n][MAX_VARS];

    bool use[n][MAX_VARS];
    bool def[n][MAX_VARS];

    mem(use, 0);
    mem(def, 0);

    repp(i,n){
        cout<<"Enter the number of statements in block B"<<i<<": ";
        int n_line;
        cin>>n_line;
        block_size[i] = n_line;

        cout<<"\nEnter "<<n_line<<" lines (Note: tokens should be seperated by space)\n";
        // char line[100];
        string line;
        getchar();
        repp(j, n_line){
            getline(cin,line);
            
            istringstream iss(line);
            copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(blocks[i][j]));
            
            // // uncomment to get input
            // for (auto& it : blocks[i][j])
            //     cout<<it<<", ";
            // nl;
        }
    }

    repp(i, n){
        int n_line = block_size[i];

        int var1;

        for(int j = n_line-1; j>=0; j--){
            if(blocks[i][j][0] == "if"){
                var1 = blocks[i][j][2][0];
                if(var1 >= 'a' && var1 <= 'z')
                use[i][var1] = true;

                var1 = blocks[i][j][4][0];
                if(var1=='='){
                    var1 = blocks[i][j][5][0];
                }

                if(var1 >= 'a' && var1 <= 'z')
                use[i][var1] = true;

            } else if(blocks[i][j][1] == "="){
                var1 = blocks[i][j][0][0];
                if(var1 >= 'a' && var1 <= 'z'){
                    def[i][var1] = true;
                    use[i][var1] = false;
                }
                

                var1 = blocks[i][j][2][0];
                if(var1 >= 'a' && var1 <= 'z')
                use[i][var1] = true;

                if(blocks[i][j].size()>3){
                    var1 = blocks[i][j][4][0];
                    if(var1 >= 'a' && var1 <= 'z')
                    use[i][var1] = true;
                }
            }
        }
    }

    // repp(i, n){
    //     repp(j, MAX_VARS){
    //         if(variables[i][j]==USE)cerr<<"USE: "<<i<<" "<<j<<endl;
    //         if(variables[i][j]==DEF)cerr<<"DEF: "<<i<<" "<<j<<endl;
    //     }
    // }

    cout<<"USE/DEF Table: \n";
    DASH_LINE;
    cout<<"Blocks\tUSE\tDEF\n";
    repp(i, n){
        cout << "B"<<i<<"\t";
        repp(j, MAX_VARS){
            if(use[i][j]) cout<<char(j)<<",";
        }
        cout<<"\t";
        repp(j, MAX_VARS){
            if(def[i][j]) cout<<char(j)<<",";
        }
        nl;
    }
    nl;

    int n_graph;
    vector<int> graph[n];

    cout<<"Enter number of directed edges between basic blocks: ";
    cin>>n_graph;
    cout<<"Enter "<<n_graph<<" lines containing two space seperated integers (0 indexed) denoting the edge (from_block to_block)\n";
    repp(i, n_graph){
        int i1, i2;
        cin>>i1>>i2;

        graph[i1].push_back(i2);    
    }

    bool in[n][MAX_VARS];
    bool out[n][MAX_VARS];
    mem(in, 0);
    mem(out, 0);

    bool changed = true;
    while(changed){
        changed = false;
        repp(i, n){
            for (auto& it : graph[i]){
                repp(j, MAX_VARS){
                    bool new_val = out[i][j] || in[it][j];
                    changed = changed || (out[i][j] != new_val);

                    out[i][j] = new_val;
                }
            }

            repp(j, MAX_VARS){
                bool new_val = (use[i][j]) || (out[i][j] && (!def[i][j]));
                changed = changed || (in[i][j] != new_val);

                in[i][j] = new_val;
            }
        }        
    }

    

    cout<<"IN/OUT Table: \n";
    DASH_LINE;
    cout<<"Blocks\tIN\tOUT\n";
    repp(i, n){
        cout << "B"<<i<<"\t";
        repp(j, MAX_VARS){
            if(in[i][j]) cout<<char(j)<<",";
        }
        cout<<"\t";
        repp(j, MAX_VARS){
            if(out[i][j]) cout<<char(j)<<",";
        }
        nl;
    }

    


    
    return 0;
}