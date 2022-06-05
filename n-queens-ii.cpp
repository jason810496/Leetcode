class Solution {
public:
    vector<bool> vis;
    int ans=0 , N;
    void solve(int r){
        if( r==N ){
            ans++;
            return;
        }
        
        for(int j=0;j<N;j++){
            int k=N+r+j , l=N*4-2+j-r;
            if( vis[j] || vis[k] || vis[l] ) continue;
            vis[j] = vis[k] = vis[l] =1;
            solve(r+1);
            vis[j] = vis[k] = vis[l] =0;
        }
    }
    int totalNQueens(int n) {
        if(n==1) return 1;
        else if(n<4) return 0;
        N=n;
        vis.resize(n*5);
        solve(0);
        return ans;
    }
};