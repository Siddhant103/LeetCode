class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        /**        
        Example 1:

        Input: nums = [4,2,4,5,6]
        Output: 17
        Explanation: The optimal subarray here is [2,4,5,6].
        Example 2:

        Input: nums = [5,2,1,2,5,2,1,2,5]
        Output: 8
        Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
        */
        
        int n = nums.size();
        int maxVal = 0;
        unordered_map<int, int> visit;
        int sum = 0;
        int start = 0;
        
        for(int i=0;i<n;i++){
            if(visit.find(nums[i]) == visit.end() || visit[nums[i]] == 0){
                sum += nums[i];
                visit[nums[i]] = 1;
            }else{
                sum += nums[i];
                while(nums[start] != nums[i]){
                    sum -= nums[start];
                    visit[nums[start]] = 0;
                    start++;
                }
                sum -= nums[start];
                start++;
            }
            maxVal = max(maxVal, sum);
        }
        
        return maxVal;
    }
};