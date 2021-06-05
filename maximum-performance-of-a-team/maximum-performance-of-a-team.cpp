class Solution {
    int MOD = pow(10, 9) + 7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> eff_speed;
        
        for(int i=0;i<n;i++){
            eff_speed.push_back({efficiency[i], speed[i]});
        }
        
        sort(eff_speed.rbegin(), eff_speed.rend());
        long sum = 0, result = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;//Min Heap
        
        for(auto [e, s] : eff_speed){
            pq.push(s);
            sum += s;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            result = max(result, sum * e);
        }
        
        return result % MOD;
    }
};