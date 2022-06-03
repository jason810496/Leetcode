#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first 
#define S second 

class Solution {
public:
    
    int n , m ;
    inline int id(int i,int j){
        return i*m+j;
    }
    int trapRainWater(vector<vector<int>>& G) {
        n=G.size() , m=G[0].size();
        if( n<3 || m<3 ) return 0;
        int total = n*m;

        bool vis[total] = {};
        priority_queue<pii, vector<pii> , greater<pii> > pq;
        
        for(int i=0;i<n;i++){
            pq.push( {G[i][0] , id(i,0)} );
            pq.push( {G[i][m-1] , id(i,m-1)} );
            vis[ id(i,0) ] = 1;
            vis[ id(i,m-1) ]=1;
        }

        for(int j=1;j<m-1;j++){
            pq.push( {G[0][j] , id(0,j) } );
            pq.push( {G[n-1][j] , id(n-1,j) } );
            vis[ id(0,j) ]=1;
            vis[ id(n-1,j) ]=1;
        }

        vector< vector<int> > pos = { {1,0} , {0,1} ,{-1,0} ,{0,-1} };

        int ans = 0;
        while( pq.size() ){
            pii cur = pq.top();
            pq.pop();

            int x=cur.S/m;
            int y=cur.S%m;
            int h=cur.F;

            for(auto &v:pos){
                int i = x+v[0] , j = y+v[1];
                if( i<0 || j<0 || i>=n || j>=m || vis[ id(i,j) ] ) continue;

                ans+=max( 0, h - G[i][j]);
                pq.push( {max(h , G[i][j] ) , id(i,j)} );
                vis[ id(i,j) ]=1;
            }
        }
        
        return ans;
    }
};

void change(){
    string str;
    getline( cin,str );
    for(char c:str){
        if( c=='[') cout<<'{';
        else if(c==']') cout<<'}';
        else cout<<c;
    }
    cout<<'\n';
}
signed main(){

    Solution solve;
    // change();

    vector< vector<int> > T1 = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    cout<<solve.trapRainWater( T1 );
    return 0;
}