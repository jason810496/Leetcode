#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pos[4][2]  = { {0,1},{1,0},{0,-1},{-1,0} };
    int n , m;
    vector< vector<int> > dp;
    int DFS(int x,int y,vector<vector<int> > &G){
        if( dp[x][y] ) return dp[x][y];
        dp[x][y] = 1;

        for(int k=0;k<4;k++){
            int i=x+pos[k][0] , j=y+pos[k][1];
            if( i<0|| j<0 || i>=n || j>=m ) continue;
            if( G[i][j] <= G[x][y] ) continue;
            dp[x][y] = max( dp[x][y] , DFS(i,j,G) +1 );
        }

        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& G) {
        n=G.size();
        m=G[0].size();

        dp.resize( n , vector<int>(m) );

        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max( ans , DFS(i,j,G) );
            }
        } 

        return ans;       
    }
};