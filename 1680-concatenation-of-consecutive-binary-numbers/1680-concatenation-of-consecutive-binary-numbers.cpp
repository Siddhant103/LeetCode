class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0, mod = 1e9+7;
        
        for(int i=1; i<=n; ++i) {
            int digits = log2(i) + 1; 
            res = ((res<<digits) % mod + i) % mod;
        }
        return res;
    }
};