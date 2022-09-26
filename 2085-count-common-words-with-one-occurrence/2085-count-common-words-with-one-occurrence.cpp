class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m1;
        for (string word: words1) {
            m1[word]++;
        }
        
        unordered_map<string, int> m2;
        for (string word: words2) {
            m2[word]++;
        }
        
        int ans = 0;
        for (auto it: m1) {
            if (it.second == 1 && it.second == m2[it.first]) {
                ans++;
            }
        }
        
        return ans;
    }
};