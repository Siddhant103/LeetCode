class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if(n <= 2){
            return result;
        }
        
        for(int i=0;i<n;i++){
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    while(left < right && nums[left] == triplet[1]){
                        left++;
                    }
                    result.push_back(triplet);
                    while(left < right && nums[right] == triplet[2]){
                        right--;
                    }
                } else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                } else{
                    right--;
                }
            }
            while(i+1 < n && nums[i] == nums[i + 1])
                i++;
        }
        
        return result;
    }
};