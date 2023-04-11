class Solution {
public:
    int romanToInt(string s) {
        int mp[105];
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int result = 0 ;
        int n = s.size();
        result += mp[ s[0] ];
        for(int i=1;i<n;i++){
            if( mp[ s[i] ] > mp[ s[i-1] ] ){
                result -= 2*mp[ s[i-1] ];
                result += mp[ s[i] ];
            }
            else{
                result += mp[ s[i] ];
            }
        }

        return result;
    }
};
