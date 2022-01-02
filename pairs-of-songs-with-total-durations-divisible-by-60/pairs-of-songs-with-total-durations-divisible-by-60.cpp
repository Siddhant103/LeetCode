class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int>mp;
        int c = 0;

        for (int i = 0; i < time.size(); i++) {
            int d = time[i]%60;
            c += d == 0 ? mp[d] : mp[60-d];
            mp[d]++;
        }

        return c;
    }
};