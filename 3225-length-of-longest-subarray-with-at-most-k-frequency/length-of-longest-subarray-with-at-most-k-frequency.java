class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer, Integer> m = new HashMap<>();
        int result = 0, start = 0, n = nums.length;
        
        for (int i=0;i<n;i++) {
            m.put(nums[i], m.getOrDefault(nums[i], 0) + 1);
            while (m.get(nums[i]) > k) {
                m.put(nums[start], m.get(nums[start++]) - 1);
            }
            result = Math.max(result, i - start + 1);
        }
        
        return result;
    }
}