class Solution {
public:
     vector<int> numberOfLines(vector<int>& widths, string s) {
        int pixels = 0, lines = 1;
        for (int i=0;i<s.length();i++) {
            int ch = s[i] - 'a';
            if ((pixels + widths[ch]) > 100){
                pixels = widths[ch];
                lines++;
            } else {
                pixels += widths[ch];
            }
        }
        return {lines, pixels};
    }
};