class Solution {
public:
    vector< vector<int> > ans ; 

    int n ;
    void DFS(int cur,int step,vector<int>　&nums){
        if( !step ){
            ans.push_back( nums );
        }
        
        for(int i=cur ; i<n;i++){
            if( i!=cur && nums[i]==nums[cur] ) continue;
            swap( nums[i] , nums[cur] );
            DFS( cur +1 , step -1 ,nums);
        }

        for(int i=n-1;i>cur;i--){
            swap( nums[cur],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin() , nums.end() );

        DFS(0,nums.size(),nums);

        return ans ;
    }
};