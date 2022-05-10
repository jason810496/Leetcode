#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> temp ; 
    vector< vector<int> > ans;
    int target;
    void DFS(int cur ,int step,int sum){
        if( !step  ){
            if( !sum ){
               ans.push_back( temp );
            }
            return ;
        }

        for(int i= cur+1 ; i<=9 ; i++){
            if( sum-i < 0 ) break;
            
            temp.push_back( i );
            DFS(i , step-1 ,sum-i );
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        target = n;

        DFS(0,k,n);

        return ans;
    }
};