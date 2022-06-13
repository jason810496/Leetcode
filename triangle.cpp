#include<bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define pii pair<int,int>
#define p pair<int , pii >

class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
       vector<int> dp = arr.back();

       for(int i=arr.size()-2 ; i>=0 ; i--){
           for(int j=0;j<arr[i].size();j++){
               dp[j] = arr[i][j] + min( dp[j] , dp[j+1] );
           }
       }

       return dp[ 0 ];
    }
};


void change(){
    string str;
    getline( cin ,str );
    for(char c : str ){
        if( c=='[') cout<<'{';
        else if( c==']') cout<<'}';
        else cout<<c;
    }
    cout<<"\n";
}
int main(){

    // change();
    Solution solve;
    vector< vector<int> > t1 ={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<solve.minimumTotal( t1 );
    return 0;
}