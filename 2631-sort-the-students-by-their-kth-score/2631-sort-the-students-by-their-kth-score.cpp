class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        int n = score.size(); 
        
        vector<pair<int,int>> v;
        for (int i=0;i<n;i++) {
            v.push_back({score[i][k], i});
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        vector<vector<int>> ans;
        for(auto &it : v) {
            ans.push_back(score[it.second]);
        }
        
        return ans;
    }
};