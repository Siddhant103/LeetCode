class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        
        for(int i=0;i<nums.size();i++){
            cout<<"nums[nums[i]-1] = "<<nums[abs(nums[i])-1]<<endl;
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1] = -1*nums[abs(nums[i])-1];
            } else{
                ans.push_back(abs(nums[i]));
            }
            
        }
        //exit(0);
        for(int i=0;i<nums.size();i++){
           // cout<<x<<" ";
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};