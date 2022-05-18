#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> vis;
    vector<int> low , dfn;
    vector< vector<int> > G;
    vector< vector<int> > ans;
    int Time = 0;

    void DFS(int cur,int par){
        dfn[ cur ] = low[ cur ] = Time++;
        vis[ cur ] = 1;
        for(int &nxt : G[cur] ){

            if( nxt == cur ) continue;

            if( !vis[ nxt] ){

                DFS(nxt,cur);
                low[ cur ] = min( low[cur]  ,low[nxt] ); 
                if( dfn[cur] < low[nxt] ){
                    ans.push_back( { cur , nxt } );
                }
            }
            else{
                low[ cur ] = min( low[cur] , dfn[nxt] );
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        G.resize(n);
        low.resize(n);
        dfn.resize(n);
        vis.resize(n);

        for(auto &e:edges){
            G[ e[0] ].push_back( e[1] );
            G[ e[1] ].push_back( e[0] );
        }

        DFS(0,-1);

        return ans;
    }
};