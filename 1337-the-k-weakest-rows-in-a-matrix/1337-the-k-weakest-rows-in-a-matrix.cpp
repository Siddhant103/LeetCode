class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    count++;
                } else{
                    break;
                }
            }
            pq.push(make_pair(count, i));
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> result;
        int s = pq.size();
        while(s--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};