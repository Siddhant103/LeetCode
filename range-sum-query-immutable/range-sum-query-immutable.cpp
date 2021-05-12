class NumArray {
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
        }
        this->nums = nums;
        
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
    }
    
    int sumRange(int left, int right) {
        
        /*
        ["NumArray","sumRange","sumRange","sumRange"]
        [[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]
        
        -2 , -2 , 1, -4 -2 -3
        */
        
        return nums[right] - (left-1>=0 ? nums[left-1]:0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */