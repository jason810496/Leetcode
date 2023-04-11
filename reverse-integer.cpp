class Solution {
public:
    int reverse(int x) {
        int sign = (x<0 ? -1:1);
        int result=0;
        x = abs(x);
        while(x){
            int last = x%10;
            x/=10;
            if( result > INT_MAX/10 || result <0 ) return 0;
            result*=10;
            result+=last;
        }
        return result*sign;
    }
};
