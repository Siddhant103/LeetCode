class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, pair<int,int>>> pq;
        vector<vector<int>> result;
        
        for(int i=0;i<points.size();i++){
            int distance = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({distance, {points[i][0], points[i][1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            pair<int, int> temp = pq.top().second;
            pq.pop();
            result.push_back({temp.first, temp.second});
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};