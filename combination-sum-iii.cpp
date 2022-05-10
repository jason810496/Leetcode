#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> temp ; 
    vector< vector<int> > ans;
    int sum = 0;
    int target;
    void DFS(int cur ,int step){
        if( !step || sum > target || cur == 10 ){
            if( sum  == target && step==0 ){
                ans.push_back( temp );
            }
        
            return ;
        }
        sum+=cur;
        temp.push_back( cur );
        DFS(cur+1,step-1);
        sum-=cur;
        temp.pop_back();
        DFS(cur+1,step);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        target = n;

        DFS(1,k);

        return ans;
    }
};