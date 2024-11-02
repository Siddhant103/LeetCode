class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int r = 0, n = s.length();
        
        if (n > 0) {
            ans += s[0];
        }
        
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                r++;
            } else {
                r = 0;
            }
            
            if (r < 2) {
                ans += s[i];
            }
        }
        
        return ans;
    }
};
