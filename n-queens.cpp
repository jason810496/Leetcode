#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void slove(vector<vector<string>> &ans,vector< string > &valid,vector< bool > &vis,int row,int n){
        if( row ==n ){
            ans.push_back( valid ) ;
            return ;
        }

        for(int j=0;j<n;j++){
            int k = n+row+j , l = 4*n -2 + j- row;
            if( vis[j] || vis[ k ] || vis[ l ]) continue;
            
            vis[j] = vis[k]=vis[l]=1;
            valid[row][j]='Q';
            slove(ans,valid,vis,row+1,n);
            vis[j]=vis[k]=vis[l]=0;
            valid[row][j]='.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector< string > valid( n , string(n,'.') );
        vector< bool > vis(n*5);

        slove(ans,valid,vis,0,n);

        return ans;
    }
};

int main(){

    Solution solve;
    solve.solveNQueens(4);
    return 0;
}