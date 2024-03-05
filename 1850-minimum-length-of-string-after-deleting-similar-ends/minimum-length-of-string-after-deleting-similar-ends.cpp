class Solution {
public:
    int minimumLength(string s) {
        if(s.length() <= 1)
            return s.length();

        int l = 0, r = s.length() - 1;
        while(l < r && s[l] == s[r]) {
            char ch = s[l];
            while(l <= r && s[l] == ch)
                ++l;
            while(l <= r && s[r] == ch)
                --r;
        }
        return r - l + 1;
    }
};