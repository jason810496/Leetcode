#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int A, int B) {
        if( A==B ) return 1;
        bool pos = (A>0 == B>0 );

        unsigned int a = abs(A);
        unsigned int b = abs(B);

        unsigned int ans=0;
        while( a >= b ){
            int cnt=0;
            for(; a>= (b<<(cnt+1))  ; cnt++);
            ans+=(1<<cnt);
            a-=(b<<(cnt));
        }

        if( ans==(1<<31) && pos ) return INT_MAX;

        return ( pos ? ans : -ans );
    }
};

int main(){
    Solution solve;

    solve.divide(1,1);
    return 0;
}