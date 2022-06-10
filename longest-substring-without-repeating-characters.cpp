class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> M;
        int ans=0 , L=0 , i=0;
        for(char c:s){
            if( M[c]==1 ){
                while( s[L]!= c){
                    M[ s[L] ]--;
                    L++;
                }
                L++;
            }
            else M[c]++;

            ans=max( ans, i-L+1 );
            i++;
        }

        return ans;
    }
};