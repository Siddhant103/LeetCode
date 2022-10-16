class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int index = 0, start = -1, maxLen = 0;
        
        while (index < s.size()) {
            if (m.count(s[index]) != 0) {
                start = max(start, m[s[index]]);
            }
            m[s[index]] = index;
            maxLen = max(maxLen, index - start);
            index++;
        }
        
        return maxLen;
    }
};