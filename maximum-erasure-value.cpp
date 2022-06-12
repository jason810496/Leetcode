class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int len =0 ,  n =nums.size();
        if( n==1 ) return nums.back();
        unordered_map< int ,int > Mp;
        
        int ans=0 , sum=0, L=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            Mp[ nums[i] ]++;
            while( Mp[ nums[i] ]>1 ){
                sum-=nums[L];
                Mp[ nums[L] ]--;
                L++;
            }
            
            // cout<<i-L+1<<"\n";
            ans = max( ans , sum );
        }
        return ans;
    }
};