#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long 
class Solution {
public:
    bool Zero;
    ll Pow(int k){
        if( k<=0 ) return 1LL;
        if( !(k&1) ){
            ll t = Pow(k/2);
            return t*t;
        }
        return 2*Pow(k-1);
    }

    void Check(deque<int> &arr,vector<bool> &vis,ll &Total){
        ll cur=0 , b=1;
        for(auto bit:arr){
            cur+= bit*b;
            b<<=1;
        }

        if( !vis[ cur ] ){
            vis[cur]=1;
            Total-=cur;
            // cout<<cur<<'\n';

            if( cur==0 ) Zero=1;
        }
    }
    bool hasAllCodes(string s, int k) {
        // cout<<" ======= \n";
        Zero=0;
        int n = s.size();
        ll base = Pow(k);
        ll Total = ( base*( base-1 ) )/2;
        // cout<<Total<<'\n';
        
        deque<int> arr(k);
        vector<bool> vis(base);
        for(int i=0;i<k;i++){
            arr[i] = int(s[i]-'0');
        }
        Check(arr,vis,Total);
        for(int i=k;i<n;i++){
            arr.pop_front();
            arr.push_back( int(s[i]-'0') );

            Check(arr,vis,Total);
        }
        
        return Zero&&Total==0;
    }
};

int main(){

    Solution solve;

    cout<<solve.hasAllCodes("00110110", 2)<<'\n';
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