#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& arr) {
        sort(arr.begin()  ,arr.end() , [&](const string &a,const string &b){
            return a.size() < b.size() ;
        });

        unordered_map< string ,int > dp;
        int ans = 1;

        for(string &str:arr){

            for(int i=0;i<str.size();i++){
                string pre = str.substr(0,i) + str.substr(i+1);

                dp[ str ] = max( dp[str] , ( dp.find(pre)==dp.end() ? 1:dp[pre]+1) );
            }
            ans = max( ans , dp[str] );
        }

        return ans;
    }
};