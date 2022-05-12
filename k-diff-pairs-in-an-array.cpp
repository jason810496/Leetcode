
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end() );
        // nums.resize( unique(nums.begin() , nums.end() ) );

        int n = nums.size() ;
        unordered_set<int> S;
        for(auto i = nums.begin() ;i!=nums.end() ; i++){
            bool check =binary_search( (i+1) , nums.end() , *i+k );
            if( check ) S.insert( *i );
        } 

        return S.size() ;
    }
};