class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0, res=INT_MIN;

				// Sliding window of size k to calculate max sum of last k elements
        for(int i=0;i<nums.size();i++) {
            if (i < k) {
							sum += nums[i];
						} else {
                res = max(sum, res);
                sum += nums[i] - nums[i - k];
            }
        }

				// Calculate final answer based on the max sum
        res = max(sum, res);
        return res / k;
    }
};