class Solution {
public:
    /*
    S1 + S2 = sum 
    S1 - S2 = target

    S1*2 = sum + target

    S1 = ( sum + target )/2
    
    if S1 -> odd : impossible 
    */
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0 ,T , n = nums.size() ;
        for(const int &i : nums ) sum+= i ;

        T = sum+target ; 
        if( T%2 || target > sum || target < -sum ) return 0;

        T/=2;

        vector< vector<int> > dp( n+1 , vector<int>(T+1) );

        for(int i=0;i<n;i++) dp[i][0] = 1 ; 

        for(int i=1;i<=n;i++){
            for(int w = 0 ; w<= T ; w++){
                if( w< nums[ i-1 ] ){
                    dp[i][w] = dp[i-1][w];
                }
                else{
                    dp[i][w] = dp[i-1][w] + dp[i-1][w - nums[i-1] ];
                }
            }
        }

        return dp[n][T];
        
    }
    
    
};