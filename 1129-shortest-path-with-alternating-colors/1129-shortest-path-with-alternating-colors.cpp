class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
        
       vector<vector<int>> bAdj(n);
        vector<vector<int>> rAdj(n);
        
        for(int i=0;i<r.size();i++)
        {
            rAdj[r[i][0]].push_back(r[i][1]);
        }
        
        for(int i=0;i<b.size();i++)
        {
            bAdj[b[i][0]].push_back(b[i][1]);
        }
        
        queue<pair<int,int>> q;
        vector<pair<int,int>> res(n,{INT_MAX,INT_MAX});
        res[0]={0,0};
        q.push({0,-1});
        q.push({0,1});
        int currDist=0;
        while(!q.empty()) {
            int l=q.size();
            for(int m=0;m<l;m++) {
                auto [node,edge]=q.front();
                q.pop();
                if(edge==1) {
                    for(auto x:rAdj[node]) {
                        if(res[x].second > currDist+1) {
                            q.push({x,-1});
                            res[x].second=currDist+1;
                        }
                    }
                } else {
                    for(auto x:bAdj[node]) {
                        if(res[x].first > currDist+1) {
                            q.push({x,1});
                            res[x].first=currDist+1;
                        }
                    }
                }
            }
            currDist++;
        }
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++) {
            int mini=min(res[i].first,res[i].second);
            ans[i]=(mini==INT_MAX) ? -1 : mini;
        }
        return ans;
        
    }
};