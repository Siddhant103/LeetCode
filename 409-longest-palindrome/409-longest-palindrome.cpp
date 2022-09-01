class Solution {
public:
    int longestPalindrome(string s) {
        int charArray[125] = {0};
        for (char c: s) {
            charArray[c]++;
        }
        
        int odd = 0;
        int ans = 0;
        for (int i=0;i<125;i++) {
            if (charArray[i] >= 2) {
                ans += ((charArray[i] / 2) * 2);
                if (charArray[i] % 2 == 1) {
                    odd = 1;
                }
            } else if (charArray[i]>0) {
                odd = 1;
            }
            cout << charArray[i] << " " << odd << endl;
        }
        
        ans += odd;
        return ans;
    }
};