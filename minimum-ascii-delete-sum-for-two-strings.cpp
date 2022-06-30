
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int total=0;
        for(int i:s1) total+=i;
        for(int i:s2) total+=i;
        int n = s1.size() , m = s2.size();
        
        vector< vector<int> > dp(n+1 , vector<int>(m+1) );
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if( s1[i-1]==s2[j-1] ){
                    dp[i][j] = dp[i-1][j-1]+s1[i-1];
                }
                else{
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
                }
            }
        }
    
        return total-dp[n][m]*2;
    }
};