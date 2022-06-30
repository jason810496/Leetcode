class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long ans=0;
        int n=nums.size() , mid=n/2;
        sort(nums.begin() , nums.end() );
        for(int i=0;i<n;i++){
            ans+= abs(nums[i]-nums[mid]);
        }
        return ans;
    }
};