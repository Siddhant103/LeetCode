class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
     
        sort(points.begin(), points.end());
        int n = points.size(), cnt = 1, minX = points[0][0], maxX = points[0][1];
        for(int i=1;i<n;i++)
        {
            if(points[i][0] > minX)
                minX = points[i][0];
            if(points[i][1] < maxX)
                maxX = points[i][1];
            if(minX > maxX) {
                cnt++;
                minX = points[i][0];
                maxX = points[i][1];
            }
                
        }
        return cnt;
    }
};