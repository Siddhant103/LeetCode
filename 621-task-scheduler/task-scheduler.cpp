class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> m(26, 0);
        for (char c: tasks) {
            m[c - 'A']++;
        }
        
        for (int i=0;i<26;i++) {
            if (m[i])
                pq.push(m[i]);
        }
        
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            
            while (cycle && !pq.empty()) {
                int top = pq.top();
                pq.pop();
                if (top > 1) {
                    temp.push_back(top - 1);   
                }
                cycle--;
                time++;
            }
            for (int count: temp) {
                pq.push(count);
            }
            if (pq.empty()) {
                break;
            }
            time += cycle;
        }
        
        return time;
    }
};