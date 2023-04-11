class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int target2 = target - nums[i];
            if( mp.count(target2) ){
                ans = { mp[target2] , i };
                break;
            }
            mp[ nums[i] ] = i;
        }

        return ans;
    }
};
