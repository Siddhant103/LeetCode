class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> nums(130, 0);
        
        for (char c: s) {
            nums[c]++;
        }
        
        int ans = 0, odd = 0;
        
        for (int i=0;i<130;i++) {
            ans += ((nums[i] / 2) * 2);
            odd = odd || nums[i] % 2;
        }
        
        return ans + odd;
    }
};