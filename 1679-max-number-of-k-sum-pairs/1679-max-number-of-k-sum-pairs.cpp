class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // support variables
        int res = 0, i = 0, j = nums.size() - 1, tot;
        // preparing nums
        sort(begin(nums), end(nums));
        while (i < j) {
            tot = nums[i] + nums[j];
            // first case: tot is a match
            if (tot == k) i++, j--, res++;
            // second case: tot is too small
            else if (tot < k) i++;
            // third case: tot is too large
            else j--;
        }
        return res;
    }
};