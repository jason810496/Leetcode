#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1);

        prefix[1] = nums[0];
        for(int i=2;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        
        vector<int> ans;
        int Mx=0 ,cur=0 , Zero=0 , One;

        for(int i=1;i<=n;i++){
            One = prefix[n] - prefix[i-1];

            cur = One+Zero;
            

            // cout<<i<<" : "<<Zero<<' '<<One<<'\n';

            if( cur > Mx ){
                Mx = cur ;
                ans.clear();
            }
            if( cur == Mx ){
                ans.push_back(i-1);
            }
            
            Zero+=(!nums[i-1] ? 1:0);
        }

        One = 0 ;

        cur = One+Zero;

        if( cur > Mx ){
            Mx = cur ;
            ans.clear();
        }
        if( cur == Mx ){
            ans.push_back(n);
        }

        
        return ans;
    }
};

int main(){
    Solution solve;

    vector<int> t1 = {0,0,1,0};
    vector<int> t2 = {0,0,0};
    vector<int> t3 = {1,1};
    auto ans = solve.maxScoreIndices(t3);

    for(auto i :ans ){
        cout<<i <<' ';
    }
    return 0;
}