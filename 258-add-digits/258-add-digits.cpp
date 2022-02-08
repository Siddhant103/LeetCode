class Solution {
public:
    int addDigits(int num) {
       int singledigit = (num-1) % 9 +1 ;
        
        return singledigit;
    }
};