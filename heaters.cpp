class Solution {
public:
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort( heaters.begin() , heaters.end() ) ;
        int ans = 0 ;

        for(int pos : houses ){
            auto it = lower_bound( heaters.begin() , heaters.end() , pos );
            int d = 1e9;
            if( it != heaters.end() ) d = min( d , *it - pos );
            if( it != heaters.begin() ) d= min( d, pos - *(it-1));
            ans = max( ans , d) ;
        }

        return ans ;
    }
};