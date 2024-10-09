class Solution {
public:
    int minAddToMakeValid(string S) {
        int res = 0, n = S.size(), balance = 0;
        for (int i = 0; i < n; i++) {
            balance += S[i] == '(' ? 1 : -1;
            if (balance == -1) {
                res++;
                balance++;
            }
        }
        return res + balance;
    }
};