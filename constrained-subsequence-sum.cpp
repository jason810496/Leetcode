class Solution {
public:
    int constrainedSubsetSum(vector<int>& arr, int k) {
        int n = arr.size();
        int ans=arr[0] , cur ;

        priority_queue<pair<int,int> , vector< pair<int,int> > > pq;
        pq.push( { arr[0] , 0 } ); 
        for(int i=1;i<n;i++){
            while( pq.size() && pq.top().second + k < i ) pq.pop();
            cur = max( 0  , (pq.size() ? pq.top().first:0) ) + arr[i];
            ans = max( ans , cur );
            pq.push( { cur , i } );
        }

        return ans;
    }
};