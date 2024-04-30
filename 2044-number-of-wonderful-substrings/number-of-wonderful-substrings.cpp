class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int cnt[1024] = {0}; // save the bitmask from 0 to current index
        int list[10], i;
        for (i = 0; i < 10; ++i) list[i] = 1 << i; // base bitmasks from 'a' to 'j'
        int cur = 0, x;
        long long ans = 0;
        cnt[0] = 1;
        for (char c : word) {
            c -= 'a';
            cur ^= (1 << c); // the current bitmask from 0 to current index
            ans += cnt[cur]; // add count that make current value to zero
            for (i = 0; i < 10; ++i) {
                x = list[i] ^ cur; // the bitmask that make current value to ith base bitmask
                ans += cnt[x]; // add count
            }
            ++cnt[cur]; // count up for the current bitmask
        }
        return ans;
    }
};