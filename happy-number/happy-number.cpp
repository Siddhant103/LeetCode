class Solution {
public:
    int getSquaredSum(int num){
        int sum=0;
        while(num){
            int ones = num%10;
            sum += ones*ones;
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n, fast=n;
        
        do{
            slow = getSquaredSum(slow);
            fast = getSquaredSum(fast);
            fast = getSquaredSum(fast);
        } while(slow!=fast);
        
        if(slow==1)
            return true;
        return false;
    }
};