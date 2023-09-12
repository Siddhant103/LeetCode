class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool isComment = false;
        string cur = "";
        vector<string> ans;

        for (string s : source) {
            int n = s.length();
            int i = 0;

            while (i < n) {
                if (!isComment && i < n - 1 && s[i] == '/' && s[i + 1] == '*') {
                    isComment = true;
                    i++;
                } else if (isComment && i < n - 1 && s[i] == '*' && s[i + 1] == '/') {
                    isComment = false;
                    i++;
                } else if (!isComment && i < n - 1 && s[i] == '/' && s[i + 1] == '/') {
                    break;
                } else if (!isComment) {
                    cur += s[i];
                }
                i++;
            }

            if (!isComment && cur.length() > 0) {
                ans.push_back(cur);
                cur = "";
            } 
        }

        return ans;
    }
};