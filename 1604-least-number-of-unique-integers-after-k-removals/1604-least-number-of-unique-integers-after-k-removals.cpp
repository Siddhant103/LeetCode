class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (auto a : arr){
            freq[a]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto& f : freq) {
            pq.push(f.second);
        }
            
        while (k > 0) {
            k -= pq.top();
            if (k >= 0) {
                pq.pop();
            }
        }

        return pq.size();
    }
};