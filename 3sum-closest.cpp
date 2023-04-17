class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = 1e9;
        int ans = target;

        int n = nums.size();

        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int l = i;
            int mid = i+1;
            int r = n-1;
            int sum , tmp;

            while(mid<r){
                sum = nums[l]+nums[mid]+nums[r];
                if( sum == target ) return sum;
                tmp = abs(sum-target);
                if( tmp < diff ){
                    diff = tmp;
                    ans = sum;
                }
                if( sum > target ) r--;
                else mid++;
            }
        }

        return ans;
    }
};