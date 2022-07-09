/*
    reference : 
    https://leetcode.com/problems/critical-connections-in-a-network/discuss/382638/DFS-detailed-explanation-O(orEor)-solution

    concept : crital bridge must not contain in a cycle

    optimize : instead of removing edges , add critical bridge to ans 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int N;
    const int NO_RANK = -2;
    
    vector<int> rank;
    vector< vector<int> > G , ans ;

    int DFS(int cur , int depth ){
        if( rank[cur]!=NO_RANK ) return rank[cur];

        rank[ cur ] = depth ;
        int minRank = depth ;

        for(auto &nxt : G[ cur ] ){
            if( rank[ nxt ]  == depth-1 || rank[nxt]>depth) continue;

            int neighborRank = DFS( nxt , depth+1 );
            minRank = min( minRank , neighborRank );
            if( neighborRank > depth ){
                ans.push_back( {min(cur,nxt) , max( cur,nxt) } );
            }
        }

        return minRank;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        N = n;
        rank.resize( n  , NO_RANK );
        G.resize( n );

        for( auto &e : edges ){
            G[ e[0] ].push_back( e[1] );
            G[ e[1] ].push_back( e[0] );
        }

        DFS(0,0);

        return ans;
    }
};