class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if( n == 3 ){
            if( nums[0]+nums[1]+nums[2] == 0 ) return {{nums[0],nums[1],nums[2]}};
            else return {};
        }

        vector< vector<int> > ans;

        sort(nums.begin(),nums.end());

        int last = -1e6;
        for(int i=0;i<n-2;i++){
            // avoid mutil answer
            if( last == nums[i] ){
                continue;
            }
            else last = nums[i];

            int l = i;

            int mid =  i+1 ;
            int r = n-1;
            int sum = 0;
            while(mid<r){
                sum = nums[l] + nums[mid] + nums[r];
                if( sum == 0 ){
                    ans.push_back({nums[l],nums[mid],nums[r]});
                    mid++;
                }
                else if( sum > 0 ){
                    r--;
                }
                else mid++;
            }
        }

        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};