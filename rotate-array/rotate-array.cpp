class Solution {
public:
    void rotate(vector<int>& nums, int k) {
     
        int i, j, n = nums.size();
        
        if(k > n)
            k = k % n;
        
        i = 0;
        j = n - k - 1;
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++; j--;
        }
        
        /*for(int k=0;k<n;k++)
            cout << nums[k] << " ";
        cout << endl;*/
        
        i = n - k;
        j = n - 1;
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++; j--;
        }
        /*for(int k=0;k<n;k++)
            cout << nums[k] << " ";
        cout << endl;*/
        
        i = 0;
        j = n - 1;
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++; j--;
        }
        
        
        /*for(int k=0;k<n;k++)
            cout << nums[k] << " ";
        cout << endl;*/
    }
};