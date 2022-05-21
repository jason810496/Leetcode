#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector< vector<int> > dp;

    int solve(int idx,int k ,vector<vector<int> > &arr){
        if( k<=0 || idx>=arr.size() ) return 0;
        if( dp[idx][k] > 0 ) return dp[idx][k];

        int res = solve(idx+1 ,k , arr ); // skip it 
        int sum = 0 ;

        for(int i=0 ; i<arr[idx].size() && i<k ; i++){
            sum+=arr[idx][i];
            res = max( res , solve(idx+1 , k - (i+1) , arr ) +sum );
        }

        dp[idx][k] = res;
        return dp[idx][k] ;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp.resize( piles.size() +1 , vector<int>(k+1 , 0 ) );

        return solve(0  , k ,piles);
    }
};

/*

WA : 

[[48,14,23,38,33,79,3,52,73,58,49,23,74,44,69,76,83,41,46,32,28]]

{{48,14,23,38,33,79,3,52,73,58,49,23,74,44,69,76,83,41,46,32,28}}
10

Output
480
Expected
421

*/

void Change_Bracket(){
    string str;
    cin>>str;
    for(char &c : str){
        if( c=='[') c='{';
        else if( c==']') c='}';
    }
    cout<<str;
}

int main(){
    Solution sol;

    vector< vector<int> > Test = {{48,14,23,38,33,79,3,52,73,58,49,23,74,44,69,76,83,41,46,32,28}} ;
    cout<< sol.maxValueOfCoins( Test , 10 );

    // Change_Bracket();

    return 0; 
}