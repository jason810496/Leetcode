
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map <int,int> M;

        for(int i :nums ){
            M[ i ]++;
        }

        int ans = 0 ;
        for(const auto P: M){
            if( k==0 ){
                if( P.second > 1 ) ans++;
            }
            else if ( M.find( P.first+k) != M.end() ) ans++;
        }

        return ans ;
    }
};