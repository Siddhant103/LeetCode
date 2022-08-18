class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        int n = arr.size();
        int count = 0;
        
        for(int i: arr){
            m[i]++;
        }
        
        priority_queue<int> pq;
        for(auto it: m){
            pq.push(it.second);
        }
        
        while(n > arr.size() / 2){
            n -= pq.top();
            pq.pop();
            count++;
        }
    
        
        return count;
    }
};