class Solution {
public:
    int minimumDeletions(string s) {
        int countb = 0;
        int ans = 0;
        for (auto i:s) {
            if (i == 'b') {
                countb++;
            }
            if (i == 'a' && countb > 0) {
                ans++;
                countb--;
            }
        }

        return ans;
    }
};