/*
    AC
    meet in middle solution 
    40 ms, faster than 50.93% 

*/

class Solution {
public:
    vector<int> Set1;
    unordered_map<int,int> Set2;
    int n , l , m ,r;
    int cur=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size() ; 
        l=0 , m=n/2 , r=n-1;
        dfs1(nums , l , 0 );
        dfs2(nums , m , 0 );
        
        int ans = 0 ;
        
        for(int a:Set1){
            ans+=Set2[ target-a];
        }
        
        return ans;
    }
    
    void dfs1(vector<int>& nums,int idx,int val){
        if( idx == m){
            Set1.push_back(val);
            return ;
        }
        dfs1(nums, idx+1 , val+nums[idx] );
        dfs1(nums, idx+1 , val-nums[idx] );
    }
    
    void dfs2(vector<int>& nums,int idx,int val){
        if( idx == n ){
            Set2[ val ] ++;
            return ;
        }
        
        dfs2(nums, idx+1 , val+nums[idx] );
        dfs2(nums, idx+1 , val-nums[idx] );
    }
};