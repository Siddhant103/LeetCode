class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        
        auto comp = [rCenter, cCenter](vector<int>& a, vector<int>& b){
            return abs(a[0]-rCenter) + abs(abs(a[1])-cCenter) > abs(b[0]-rCenter) + abs(abs(b[1])-cCenter);
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                pq.push({i, j});
            }
        }
        
        vector<vector<int>> ans;
        while(pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};