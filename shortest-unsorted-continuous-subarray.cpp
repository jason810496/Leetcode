class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size() ; 
        vector<int> Min(n) , Max(n);
        
        
        Max[0] = nums[0];

        for(int i=1;i<n;i++){
            Max[i]=max( Max[i-1]  , nums[i]);
        }

        Min[n-1] = nums[n-1];
        for(int i=n-2 ; i>=0 ; i--){
            Min[i]=min(Min[i+1] , nums[i] );
        }

        int L=0 ,R=n-1;

        while( L<n && Min[L]==Max[L]) L++;
        while( L<R && Min[R]==Max[R]) R--;


        return (L==R ? 0:R-L+1);
    }
};