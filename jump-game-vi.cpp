class Solution {
public:
    int maxResult(vector<int>& arr, int k) {

        deque<int> dq;
        dq.push_back( 0 );

        for(int i=1;i<arr.size();i++){
            if( dq.size() ) arr[i]+=arr[ dq.front() ];

            while( dq.size() && arr[i]>arr[ dq.back() ] ){
                dq.pop_back();
            }
            while( dq.size() && dq.front()+k<=i ) dq.pop_front();
            dq.push_back( i );
        }

        return arr.back();
    }
};