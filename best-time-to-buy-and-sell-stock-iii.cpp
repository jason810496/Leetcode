class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n<=1 ) return 0;

        int cost1 = 1e9;
        int cost2 = 1e9;
        int profit1 = 0;
        int profit2 = 0;
        for(int i=0;i<n;i++){
            int p = prices[i];
            cost1 = min( cost1 , p );
            profit1 = max( profit1 , p - cost1 );
            cost2 = min( cost2 , p - profit1 );
            profit2 = max( profit2 , p - cost2 );
        }
        return profit2;
    }
};