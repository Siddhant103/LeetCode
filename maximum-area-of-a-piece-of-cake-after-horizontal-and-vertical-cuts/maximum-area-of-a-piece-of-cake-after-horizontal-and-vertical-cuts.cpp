class Solution {
    int MOD = pow(10, 9) + 7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHeight = 0;
        int maxWidth = 0;
        
        maxHeight = max(horizontalCuts[0] - 0, h - horizontalCuts[horizontalCuts.size() - 1]);
        maxWidth = max(verticalCuts[0] - 0, w - verticalCuts[verticalCuts.size() - 1]);
        
        for(int i=1;i<horizontalCuts.size();i++){
            maxHeight = max(maxHeight, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        
        for(int i=1;i<verticalCuts.size();i++){
            maxWidth = max(maxWidth, verticalCuts[i] - verticalCuts[i - 1]);
        }
        
        long maxArea = ((long(maxHeight) * long(maxWidth))) % MOD;
        return maxArea;
    }
};