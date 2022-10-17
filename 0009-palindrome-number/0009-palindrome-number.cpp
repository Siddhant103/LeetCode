class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        long rev=0;
        int orig_num=x;
        
        while(x){
            rev = rev*10 + (x%10);
            x/=10;
        }
        if(rev>INT_MAX)
            return false;

        if(orig_num == int(rev))
            return true;
        else 
            return false;
    }
};