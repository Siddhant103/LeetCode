class Solution {
public:
    long long solveCost(vector<int>& nums, vector<int>& cost_arr, int x){
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += (long)abs(nums[i]-x)*cost_arr[i];
        }
        return ans;
    } 

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int start = 1, end = 1e6;
        long long y1,y2;
        while(start<end){
            int mid = start + (end-start)/2;
            y1 = solveCost(nums,cost,mid);
            y2 = solveCost(nums,cost,mid+1);
            if(y1>y2){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return min(y1,y2);
    }
};