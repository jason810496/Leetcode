#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> z;

    int extend(string &str,int l,int r){
        int i =0;
        while( l-i>=0 && r+i<n && str[l-i]==str[r+i] ){
            i++;
        }

        return i;
    }

    string longestPalindrome(string s) {
        n = s.size()*2+1;
        z.resize( n );
        string str(n,'.') , ans;

        for(int i=0;i<s.size();i++){
            str[i*2+1] = s[i];
        }

        z[0]=1;
        int L = 0  , R=0 ;

        for(int i=1;i<n;i++){
            int ii= L - (i-L);
            int len = R-i+1;

            if( i>R ){
                z[i] = extend(str,i,i);
                L=i;
                R=z[i]+i-1;
            }
            else if( z[ii] == len ){
                z[i] = len + extend(str,i-len,i+len);
                L=i;
                R=z[i]+i-1;
            }
            else{
                z[i] = min( z[ii] , len );
            }

        }

        int idx=0 , mx=0;

        for(int i=1;i<n;i++){
            if( z[i] > mx ){
                mx = z[ idx = i ];
            }
        }

        for(int i=idx - z[idx]+1 ; i<=idx+z[idx]-1 ;i++){
            if( i&1 ){
                ans.push_back( str[i] );
            }
        }
        
        return ans;
    }
};