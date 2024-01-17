class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (auto point: points) {
            int dist = point[0]*point[0] + point[1]*point[1];
            pq.push({dist, {point[0], point[1]}});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<vector<int>> result;
        
        while (!pq.empty()) {
            auto temp = pq.top(); pq.pop();
            result.push_back({temp.second.first, temp.second.second});
        }
        
        return result;
    }
};