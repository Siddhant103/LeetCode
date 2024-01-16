class Solution {
public:
    bool isPalindrome(string s1) {
        string s;
        for (char c: s1) {
            if (c >= 65 && c <= 90) {
                s += c+32;
            } else if (c >= 48 && c <= 57) {
                s += c;
            } else if (c >= 97 && c <= 122) {
                s += c;
            }
        }
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};