class Solution {
public:
    int reverse(int x) {
        int reversedInteger = 0;
        int lastDigit;
        
        while(x!=0){
            lastDigit = x%10;
            x/=10;
            
            if(reversedInteger>INT_MAX/10)
                return 0;
            if(reversedInteger<INT_MIN/10)
                return 0;
            reversedInteger = (reversedInteger*10)+lastDigit;
        }
        
        return reversedInteger;
    }
};