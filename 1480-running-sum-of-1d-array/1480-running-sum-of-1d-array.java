class Solution {
    public int[] runningSum(int[] nums) {
        int n = nums.length;
        int[] runSum = new int[n];
        runSum[0] = nums[0];
        for(int i=1;i<n;i++){
            runSum[i] = nums[i]+runSum[i-1];

        }
        return runSum;
    }
}