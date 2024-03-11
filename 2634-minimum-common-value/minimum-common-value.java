class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        Map<Integer, Integer> m = new HashMap<>();
        for (int num: nums1) {
            m.put(num, m.getOrDefault(num, 0) + 1);
        }
        
        for (int num: nums2) {
            if (m.containsKey(num)) {
                return num;
            }
        }
        
        return -1;
    }
}