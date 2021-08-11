class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if(k == arr.size())
            return 0;
        
        unordered_map<int, int> m;
        for(int a: arr){
            m[a]++;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i: m){
            pq.push(i.second);
        }
        
        while(k>0){
            k -= pq.top();
            if(k >= 0)
                pq.pop();
        }
        
        return pq.size();
    }
};