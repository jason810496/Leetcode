#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> Map;
        
        sort(words.begin(),words.end(),[&](string &a,string&b){
            return a.size()>b.size();
        });

        int ans=0;
        for(string &str : words ){
            if( Map.count(str) ) continue;
            int len =str.size();
            ans+=1+len;
            for(int i=0;i<len;i++){
                Map.insert( str.substr(i) );
            }   
        }

        // for(auto i : Map){
        //     cout<<i<<"\n";
        // }

        return ans;
    }
};