class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int i=0;i<nums.length;i++) {
            int absValue = Math.abs(nums[i]);
            if (nums[absValue - 1] < 0) {
                result.add(absValue);
            }
            nums[absValue - 1] *= -1;
        }
        
        return result;
    }
}