class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n = strs.size();
        int idx=0;
        while(idx>=0){
            int i=0;
            for(i=0;i<n;i++){
                if( strs[i].size() == idx || strs[i][idx] != strs[0][idx] ){
                    idx=-5;
                    break;
                }
            }
            if( i==n ) ans.push_back( strs[0][idx] );
            idx++;
        }
        return ans;
    }
};
