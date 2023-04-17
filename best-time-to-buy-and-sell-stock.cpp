class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = prices[0];
        int n = prices.size();
        for(int i=1;i<n;i++){
            min_price = min( min_price , prices[i] );
            if( prices[i] - min_price > ans ){
                ans = prices[i] - min_price ;
            }
        }
        return ans;
    }
};