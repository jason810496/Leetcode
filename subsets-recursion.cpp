class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    int n;

    void helper(int cur,int cnt,int sz,vector<int> &nums){
        if( cur == n && cnt < sz ){
            return;
        }
        if( cnt == sz ){
            ans.push_back( tmp );
            return;
        }
        for(int i=cur;i<n;i++){
            tmp.push_back( nums[i] );
            helper(i+1,cnt+1,sz,nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        n = nums.size();
        for(int i=1;i<=n;i++){
            helper(0,0,i,nums);
        }
        return ans;
    }
};