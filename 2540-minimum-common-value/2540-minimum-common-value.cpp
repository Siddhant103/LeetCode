class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans = -1;
        for (int num: nums1) {
            int low = 0, high = nums2.size() - 1;
            bool found = false;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums2[mid] == num) {
                    ans = nums2[mid];
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
        return ans;
    }
};