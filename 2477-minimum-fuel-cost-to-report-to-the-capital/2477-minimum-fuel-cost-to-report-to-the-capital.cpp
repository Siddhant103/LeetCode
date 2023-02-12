class Solution 
{
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        map<int,set<int>> G;
        for (auto r : roads) G[r[0]].insert(r[1]), G[r[1]].insert(r[0]);
        
        set<int> seen = {0};
        function<pair<long long,long long>(int)> dfs;
        dfs = [&](int n) {
            long long ppl = 1, ltr = 0;
            seen.insert(n);
            
            for (int m : G[n])
                if (not seen.count(m))
                {
                    auto[p, l] = dfs(m);
                    ppl += p, ltr += l;
                }
            ltr += (ppl - 1) / seats + 1;
            
            return make_pair(ppl, ltr);
        };
        
        long long liters = 0;
        for (int n : G[0]) liters += dfs(n).second;
        return liters;
    }
};