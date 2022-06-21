#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& ht, int bricks, int ladders) {
        int n =ht.size();

        priority_queue<int , vector<int> , greater<int> > pq;
        for(int i=0;i<n-1;i++){
            int cost = ht[i] - ht[i-1];

            if( cost>0 ) pq.push( cost );

            if( pq.size()>ladders ){
                bricks-=pq.top();
                pq.pop();
            }

            if( bricks<0 ) return i;
        }

        return n-1;
    }
};
