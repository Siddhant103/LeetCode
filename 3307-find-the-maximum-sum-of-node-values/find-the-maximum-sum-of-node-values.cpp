class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> delta(n);

        for(int i = 0; i < n; i++)
            delta[i] = (nums[i] ^ k) - nums[i];

        sort(delta.begin(), delta.end(), greater<>());
        long long res = 0;

        for(auto num: nums)
            res += num;

        for(int i = 0; i < n; i += 2) {
            if(i == n - 1)
                break;

            long long pathDelta = delta[i] + delta[i + 1];
            if(pathDelta <= 0)
                break;

            res += pathDelta;
        }

        return res;    
    }
};