// #include<bits/stdc++.h>
// using namespace std;

// #define F first
// #define S second
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& G) {
        if( G[0][0] ) return 0;
        int n = G.size();
        int m = G[0].size();

        vector< vector<int> > dp(n , vector<int>(m) );

        for(int i=0;i<n;i++){
            if( G[i][0] ) break;
            dp[i][0] =1 ;
        }

        for(int i=0;i<m;i++){
            if( G[0][i] ) break;
            dp[0][i] =1 ;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(G[i][j]) dp[i][j]=0;
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
                }
            }
        }

        return dp[n-1][m-1];
    }
};