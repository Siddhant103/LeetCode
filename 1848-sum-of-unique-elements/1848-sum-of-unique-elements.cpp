class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for (auto n : nums) {
            int cnt = ++m[n];
            res += cnt == 1 ? n : cnt == 2 ? -n : 0;
        }
        return res;
    }
};