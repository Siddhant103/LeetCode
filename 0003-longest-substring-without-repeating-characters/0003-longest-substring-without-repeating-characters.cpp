class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int maxLen = 0, start = 0;
        
        for (int i=0;i<s.size();i++) {
            m[s[i]]++;
            if (m[s[i]] > 1) {
                while (m[s[i]] > 1) {
                    m[s[start]]--;
                    start++;
                }
            }
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};