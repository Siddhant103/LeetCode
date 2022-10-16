class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int size = n + m;
    
        if (!size) {
            return double(0);
        }
        
        vector<int> median;
        int i = 0, j = 0;
        while (i < n || j < m) {
            if (i < n && j < m) {
                if (nums1[i] < nums2[j]) {
                    median.push_back(nums1[i++]);
                } else {
                    median.push_back(nums2[j++]);
                }
            } else {
                if (i < n) {
                    median.push_back(nums1[i++]);
                }
                if (j < m) {
                    median.push_back(nums2[j++]);
                }
            }
        }
        
        if (size % 2) {
            return double(median[size/2]);
        }
        return double(median[size/2] + median[size/2 - 1]) / 2;
    }
};