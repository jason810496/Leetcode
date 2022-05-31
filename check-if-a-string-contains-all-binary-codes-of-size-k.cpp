#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {

        unordered_set<string> S;

        for(int i=0;i+k <=s.size();i++){
            S.insert( s.substr(i,k) );
        }

        return S.size() ==  pow(2,k);
    }
};

int main(){

    Solution solve;

    cout<<solve.hasAllCodes("00110110", 2 )<<'\n';
    cout<<solve.hasAllCodes("0110" ,1 )<<'\n';
    cout<<solve.hasAllCodes("0110" ,2 )<<'\n';
    cout<<solve.hasAllCodes("00110",2)<<'\n';

    return 0;
}

/*
"00110110"
2
"0110"
1
"0110"
2
"00110"
2
*/