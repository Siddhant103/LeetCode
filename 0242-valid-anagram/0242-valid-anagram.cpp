class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charLen(27, 0);
        
        for (char c: s) {
            charLen[c - 'a']++;
        }
        
        for (char c: t) {
            charLen[c - 'a']--;
        }
        
        for (int i=0;i<27;i++) {
            if (charLen[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};