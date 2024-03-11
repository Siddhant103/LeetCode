class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> sCount(26, 0);
        for (char c: s) {
            sCount[c - 'a']++;
        }
        
        string result = "";
        for (char c: order) {
            while (sCount[c - 'a'] != 0) {
                result += c;
                sCount[c - 'a']--;
            }
        }
        
        for (int i=0;i<26;i++) {
            while (sCount[i] != 0) {
                result += (i + 97);
                sCount[i]--;
            }
        }
        
        return result;
    }
};