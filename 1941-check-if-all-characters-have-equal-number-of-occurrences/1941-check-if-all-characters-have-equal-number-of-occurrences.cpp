class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> c(156, 0);        
        for (char ch: s) c[ch]++;
        int threshold = c[s[0]];
        for (int i=97;i<=122;i++) {
            if (!c[i]) continue;
            if (c[i] != threshold) return false;
        }
        return true;
    }
};