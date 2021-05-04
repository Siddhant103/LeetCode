class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int maxVol = 0;
        while(left<right){
            int currVol = min(height[left],height[right]) * (abs(left-right));
            if(currVol>maxVol){
                maxVol = currVol;
            }
            
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        
        return maxVol;
    }
};