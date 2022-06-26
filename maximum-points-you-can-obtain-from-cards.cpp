class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        
        vector<int> suffix(n+1);
        
        suffix[0] = 0;
        for(int i=1;i<=n;i++){
            suffix[i] = suffix[i-1] + arr[n-i];
        }
        
        int ans = suffix[k] , cur , prefix=0;
        for(int i=0;i<k;i++){
            prefix+=arr[i];
            
            cur = prefix + suffix[k-i-1];
            
            ans = max( ans , cur );
        }
        
        return ans ;
    }
};