class Solution {
public:
    int ans = 0 ;
    int n ;
    
    inline bool check( int  n ){
        int t = sqrt(n);
        return t*t==n;
    }
    void DFS(int cur ,int step , vector<int> nums){
        if( !step ){
            ans ++ ;
        }

        for(int i = cur ;i<n;i++){
            if( i!=cur && nums[i]==nums[cur] ) continue;
            swap( nums[i] , nums[cur] ) ;

            if( cur ==0 || ( cur >0 && check( nums[ cur ]+nums[ cur-1])) ){
                DFS( cur + 1 , step-1 , nums);
            }
            
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        n=nums.size();
        
        sort( nums.begin() , nums.end() ) ;
        DFS(0,n,nums);
        return ans;
    }
};