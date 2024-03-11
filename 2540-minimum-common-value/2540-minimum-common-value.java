class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int result = -1;
        for (int num: nums1) {
            int low = 0;
            int high = nums2.length - 1;
            boolean found = false;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums2[mid] == num) {
                    result = num;
                    found = true;
                    break;
                } else if (nums2[mid] > num) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (found) {
                break;
            }
        }
        
        return result;
    }
}