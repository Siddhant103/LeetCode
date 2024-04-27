class Solution {
public:
    string Ring,Key;
    map<pair<int,int>,int> memo;
    int n,m;
    unordered_map<char,vector<int>> Graph;
    int dp(int ptr,int idx){
        if (idx==n) return 0;
        if (memo.find(make_pair(ptr,idx))!=memo.end()) return memo[make_pair(ptr,idx)];
        int ans=INT_MAX;
        for (int j:Graph[Key[idx]]) ans=min(ans,dp(j,idx+1)+min(abs(ptr-j),abs(abs(ptr-j)-m)));
        return memo[make_pair(ptr,idx)]=ans;
    }
    int findRotateSteps(string ring, string key) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        Ring=ring;
        Key=key;
        m=ring.size();
        n=key.size();
        unordered_map<char,vector<int>> graph;
        for (int i=0;i<m;i++) graph[ring[i]].push_back(i);
        Graph=graph;
        return dp(0,0)+n;
    }
};