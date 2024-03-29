class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > sub(1,vector<int>(0));

        for(int num:nums){
            int n = sub.size();
            for(int i=0;i<n;i++){
                sub.push_back(sub[i]);
                sub.back().push_back(num);
            }
        }

        return sub;
    }
};