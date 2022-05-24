#include<bits/stdc++.h>
using namespace std;

// solve by stack 
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;

        stk.push(-1);
        int n = s.size();

        int MxLen = 0;
        for(int i=0;i<n;i++){
            int t = stk.top();

            if( t!=-1 && s[t]=='(' && s[i]==')' ){

                stk.pop();
                MxLen = max( MxLen , i - stk.top() );
            }
            else stk.push( i );
        }

        return MxLen;
    }
};

int main(){

    return 0;
}