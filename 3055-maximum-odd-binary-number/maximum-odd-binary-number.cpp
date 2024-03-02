class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int last_one = n - 1;
        while (last_one >= 0 && s[last_one] == '0') {
            last_one--;
        }
        if (last_one < n - 1) {
            swap(s[last_one], s[n - 1]);
        }
        sort(s.begin(), s.begin() + n - 1, greater<char>());
        return s;
    }
};