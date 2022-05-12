class Solution {
public:

    vector<int> res; 
    vector< vector<int> > ans;
    unordered_set<string> S;
    int n ;
    bool vis[8] ={};

    string Hash(){
        string str = "";
        for(int &i:res){
            str+= to_string(i);
        }
        return str;
    }
    void DFS(int step,vector<int> &nums){
        if( !step ) {
            if( res.size() == n ){
                string h = Hash();

                if( S.find(h)==S.end()){
                    ans.push_back( res ) ;
                    S.insert( h );
                }
                
            }
            return ;
        }

        for(int i=0;i<n;i++){
            if( vis[i] ) continue;
            vis[i]=1;
            res.push_back( nums[i] );
            DFS(step-1,nums);

            vis[i]=0;
            res.pop_back();
            DFS(step-1,nums);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n  = nums.size() ; 
        DFS(n,nums);
        return ans ;
    }
};