class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int cp=x;
        unsigned int reversed=0;
        while(cp){
            reversed = reversed*10 + cp%10;
            cp/=10;
        }
        return x==reversed;
    }
};
