#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define Node first 
#define Dis second // Distance

class Solution {
public:
    int move[4][2]  = { {0,1},{1,0},{0,-1},{-1,0} };
    int n , m  , nm;

    int longestIncreasingPath(vector<vector<int>>& Matrix) {
        n=Matrix.size();
        m=Matrix[0].size();
        nm = n*m;

        vector< vector<int> > Graph( nm );
        vector<int> indeg( nm );

       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               for(int k=0;k<4;k++){
                    int nxt_I = i+move[k][0] , nxt_J=j+move[k][1];
                    if( nxt_I<0 || nxt_J<0 || nxt_I>=n || nxt_J>=m ) continue;
                    // small to big
                    if( Matrix[i][j] < Matrix[ nxt_I][ nxt_J ] ){
                        // turn into 1D index 
                        int from = i*m + j ;
                        int to = nxt_I*m + nxt_J ;

                        // normal DAG
                        Graph[ from ].push_back( to );
                        ++indeg[ to ];
                    }
               }
           }
       } 

        queue< pii > q; // node , distance
        // I have define Node as first , Dis as second
        int ans=0;

        for(int i=0;i< nm ;i++){
            // push nodes that indeg==0 to queue 
            if( !indeg[i] ) q.push( {i,1} );
        }

        // topoligical sort 
        while( q.size() ){
            pii cur = q.front() ;
            q.pop();

            // update ans 
            ans = max(ans,cur.Dis);

            for(int nxt : Graph[ cur.Node ] ){ 
                if( nxt == cur.Node ) continue;

                if( !--indeg[nxt] ){ // trick 
                    q.push( { nxt ,cur.Dis+1 } );
                }
            }
        }

        return ans;       
    }
};