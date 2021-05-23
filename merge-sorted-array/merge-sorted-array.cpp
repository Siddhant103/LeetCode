class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int target = m+n-1;
        
        if(n==0)
            return ;
        
        while(i>=0 && j>=0){
            cout<< nums1[i] << " " << nums2[j] <<endl;
            if(nums1[i] >= nums2[j]){
                nums1[target] = nums1[i];
                i--;
                target--;
            } else{
                nums1[target] = nums2[j];
                j--;
                target--;
            }
        }
        
        while(i>=0){
            nums1[target--] = nums1[i--];
        }
        
        while(j>=0){
            nums1[target--] = nums2[j--];
        }
    }
};