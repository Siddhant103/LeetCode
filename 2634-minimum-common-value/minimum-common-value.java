class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        Set<Integer> s = new HashSet<>();
        for (int num: nums1) {
            s.add(num);
        }
        
        for (int num: nums2) {
            if (s.contains(num)) {
                return num;
            }
        }
        
        return -1;
    }
}