class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int maxVol = 0;
        
        while (low <= high) {
            if (height[low] < height[high]) {
                maxVol = max (maxVol, height[low] * (high - low));
                low++;
            } else {
                maxVol = max (maxVol, height[high] * (high - low));
                high--;
            }
        }
        
        return maxVol;
    }
};