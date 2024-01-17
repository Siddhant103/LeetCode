class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        int a = 1, b = 2, temp;
        for (int i=3;i<=n;i++) {
            temp = b;
            b = a + b;
            a = temp;
        }
        
        return b;
    }
};