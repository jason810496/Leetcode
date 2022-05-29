#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size() , ans=0;

        vector<int> Mask(n);

        for(int i=0;i<n;i++){
            Mask[i]=0;

            for(char c:words[i] ){
                Mask[ i ]|=(1<<(c-'a') );
            }

            for(int j=0;j<i;j++){
                if( ! (Mask[i]&Mask[j]) ){
                    ans = max( ans , int(words[i].size() * words[j].size()) );
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution solve;

    vector<string> T1 = {"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> T2 = {"a","ab","abc","d","cd","bcd","abcd"};
    vector<string> T3 = {"a","aa","aaaa"};

    cout<<solve.maxProduct(T1)<<'\n';
    cout<<solve.maxProduct(T2)<<'\n';
    cout<<solve.maxProduct(T3)<<'\n';

    return 0;
}