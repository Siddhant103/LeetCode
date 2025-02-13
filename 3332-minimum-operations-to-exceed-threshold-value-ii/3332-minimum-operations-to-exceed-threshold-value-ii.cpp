class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;  

        for (long long int it : nums) {
            pq.push(it);
        }

        long long int ans = 0;
        while (pq.top() < k) {
            long long int a = pq.top();
            pq.pop();
            long long int b = pq.top();
            pq.pop();
            ans++;

            long long int c = min(a, b) * 2 + max(a, b);
            pq.push(c);
        }

        return ans;
    }
};