class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> m = new HashMap<>();
        int n = nums.length;
        int []result = new int[2];
        
        for (int i=0;i<n;i++) {
            if (m.getOrDefault(target - nums[i], -1) == -1) {
                m.put(nums[i], i);
            } else {
                result[0] = i;
                result[1] = m.get(target - nums[i]);
                break;
            }
        }
        
        return result;
    }
}