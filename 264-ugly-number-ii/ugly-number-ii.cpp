class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0)
            return 0;
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_map<long long, bool> visited;
        pq.push(1);
        
        long long result = 1;
        visited[1] = true;
        
        while(n--){
            result = pq.top(); pq.pop();
            
            if(visited[result * 2] == false){
                visited[result * 2] = true;
                pq.push(result * 2);
            }
            
            if(visited[result * 3] == false){
                visited[result * 3] = true;
                pq.push(result * 3);
            }
            
            if(visited[result * 5] == false){
                visited[result * 5] = true;
                pq.push(result * 5);
            }
        }
        
        return result;
    }
};