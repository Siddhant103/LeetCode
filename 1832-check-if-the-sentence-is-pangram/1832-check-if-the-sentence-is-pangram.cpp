class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> letters(26, 0);
        for (char c: sentence) {
            letters[c - 'a']++;
        }
        
        for (int i=0;i<26;i++) {
            if (!letters[i]) {
                return false;
            }
        }
        return true;
    }
};