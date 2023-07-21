class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> table(n, vector<int>{});
        vector<vector<int>> paths;
        vector<int> lis;
        int i, j, k, ans = 0;
        for (auto num: nums){
            i = lower_bound(lis.begin(), 
                            lis.end(),
                            num) - lis.begin();
            k = 1;
            if (i > 0){
                j = upper_bound(table[i-1].begin(), 
                                table[i-1].end(), 
                                -num) - table[i-1].begin();
                k = paths[i-1].back() - paths[i-1][j];
            }

            table[i].push_back(-num);

            if (i == lis.size()){
                lis.push_back(num);
                paths.push_back({0, k});
            }
            else {
                lis[i] = num;
                paths[i].push_back(paths[i].back() + k);
            }
        }
        return paths.back().back();
    }
};