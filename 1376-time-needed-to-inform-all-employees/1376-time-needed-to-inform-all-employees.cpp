class Solution {
public:
    int ans=0; 
    void dfs(int n, int headID, vector<int>& manager, vector<int>& informTime, vector<vector<int>>& subordinate, int i, int time) {
        if(informTime[i]==0)
        {
            ans=max(ans,time);
            return;
        }
        time+=informTime[i];
        for(auto x:subordinate[i])
            dfs(n,headID,manager,informTime,subordinate,x,time);
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinate(n);
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                subordinate[manager[i]].push_back(i);
        }
        dfs(n,headID,manager,informTime,subordinate,headID,0);
        return ans;
    }
};