class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0 , n = nums.size();
        for(int i=0;i<n;i++){
            if( nums[i] != val ){
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
};
