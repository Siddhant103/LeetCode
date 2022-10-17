class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        string ans = "";
        
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[size - 1];
        
        for (int i=0;i<strs[0].size();i++) {
            if (first[i] == last[i]) {
                ans += first[i];
            } else {
                break;
            }
        }
        
        return ans;
    }
};