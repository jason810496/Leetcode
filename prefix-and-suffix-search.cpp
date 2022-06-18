#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

class WordFilter {
public:
    unordered_map< ll ,int > Map;
    ll MOD = 1610612741;


    void Add(string &str){
        int n = str.size();

        ll p =1 ;
        for(int i=0;i<n;i++){
            p = ( p * (str[i]-'a'+1) )%MOD;
            for(int j=0;j<n;j++){
                ll s = 1;
                for(int k=j;k<n;k++){
                    s = ( s * (str[k]-'a'+1) )%MOD;
                }

                Map[ (p*s)%MOD ]=i+1;
            }
        }
    }
    WordFilter(vector<string>& words) {

        
        for(string &word : words){
            Add(word);
        }
    }
    
    int f(string prefix, string suffix) {
        ll p=1 , s=1;
        for(char c:prefix){
            p = ( p * (c-'a'+1 ) )%MOD;
        }
        for(char c:suffix){
            s = ( s * (c-'a'+1 ) )%MOD;
        }
        return Map[ (p*s)%MOD ]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */