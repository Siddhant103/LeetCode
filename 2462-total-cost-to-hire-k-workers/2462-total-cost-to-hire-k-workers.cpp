class Solution {
    #define ll long long
public:
    long long totalCost(vector<int>& cost, int k, int c) {
        ll ans=0LL; int n=cost.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0,j=n-1;
        
        while (pq.size()<c && i<=j) 
            pq.push({cost[i++],0});
        
        while (pq.size()<2*c && i<=j) 
            pq.push({cost[j--],1});
        
        while (k--) {
            auto it = pq.top(); pq.pop();
            int top = it.first, flg = it.second;
            ans += top;
            if (i<=j) {
                if(flg) 
                    pq.push({cost[j--],1});
                else 
                    pq.push({cost[i++],0});
            }
        }
        return ans;
    }
};