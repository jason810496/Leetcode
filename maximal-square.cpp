class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if( matrix.empty() ) return false;
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector< vector<int> > dp(n , vector<int>(m) );
        
        int Size = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( !i || !j || matrix[i][j]=='0'){
                    dp[i][j] = matrix[i][j] -'0';
                }
                else{
                    dp[i][j] = min( dp[i-1][j-1] , min(dp[i-1][j],dp[i][j-1] ) )+1;
                }
                Size = max( Size  , dp[i][j] ) ;
            }
        }

        return Size * Size ;
    }
};

/*
    reference : 
    https://leetcode.com/problems/maximal-square/discuss/61803/C%2B%2B-space-optimized-DP

*/