class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if( nums.size() < 3 ) return false;
        
        int n = nums.size() , mid = INT_MIN;
        stack<int> stk;
        
        for(int i=n-1;i>=0;i--){
            if( nums[i] < mid ) return true;
            else{
                while( !stk.empty() && nums[i] > stk.top() ) {
                    mid = stk.top();
                    stk.pop();
                }
            }
            
            stk.push( nums[i] );
        }
        return false;
    }
};