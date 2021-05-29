class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        int cost = 0;
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        
        while(pq.size() != 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            cost += (a + b);
            pq.push(a + b);
        }
        
        return cost;
    }
};