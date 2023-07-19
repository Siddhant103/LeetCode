class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int target = m + n - 1;

        while (i >= 0 && j >= 0) {
            nums1[target--] = nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
            cout << nums1[target + 1];
        }
        
        while (i >= 0) {
            cout << "i = ";
            cout << i << " ";
            nums1[target--] = nums1[i--];
        }
        cout << endl;
        while (j >= 0) {
            cout << "j = ";
            cout << j << " ";
            nums1[target--] = nums2[j--];
        }
    }
};