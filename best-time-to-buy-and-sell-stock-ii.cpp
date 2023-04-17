class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int cur = prices[0];
        int n = prices.size();

        for(int i=0;i<n;i++){
            if( prices[i] > cur ){
                ans += prices[i]-cur;
                cur = prices[i];
            }
            else{
                cur = min( cur , prices[i] );
            }
        }

        return ans;
    }
};