#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define Node first 
#define Dis second

class Solution {
public:
    int pos[4][2]  = { {0,1},{1,0},{0,-1},{-1,0} };
    int n , m  , N;

    int longestIncreasingPath(vector<vector<int>>& Mat) {
        n=Mat.size();
        m=Mat[0].size();
        N = n*m;
        vector< vector<int> > G(N);
        vector<int> indeg(N);

       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               for(int k=0;k<4;k++){
                    int I = i+pos[k][0] , J=j+pos[k][1];
                    if( I<0 || J<0 || I>=n || J>=m ) continue;
                    // small to big
                    if( Mat[i][j] < Mat[I][J] ){
                        int st = i*m+j;
                        int ed = I*m+J;

                        G[st].push_back(ed);
                        ++indeg[ed];
                    }
               }
           }
       } 

        queue< pii > q; // node , distance
        int ans=0;

        for(int i=0;i<N;i++){
            if( !indeg[i] ) q.push( {i,1} );
        }

        while( q.size() ){
            pii cur = q.front() ;
            q.pop();

            ans = max(ans,cur.Dis);

            for(int nxt : G[ cur.Node ] ){
                if( nxt == cur.Node ) continue;

                if( !--indeg[nxt] ){
                    q.push( { nxt ,cur.Dis+1 } );
                }
            }
        }

        return ans;       
    }
};