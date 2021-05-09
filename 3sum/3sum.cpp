class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        if(nums.size()<3)
            return result;
        //unordered_map<string,int> checker;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();i++){
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                //cout<<nums[i]<<" "<<nums[left]<<" "<<nums[right]<<endl;
                if(nums[i] + nums[left] + nums[right] > 0){
                    right--;
                } else if(nums[i] + nums[left] + nums[right]<0){
                    left++;
                } else{
                    vector<int> triplet {nums[i], nums[left], nums[right]};
                    result.push_back(triplet);
                    while(left<right && nums[left]==triplet[1]) left++;
                    while(left<right && nums[right]==triplet[2]) right--;
                } 
            }
            while(i+1<nums.size() && nums[i+1]==nums[i])
            i++;
        }
        
        
        
        return result;
    }
};