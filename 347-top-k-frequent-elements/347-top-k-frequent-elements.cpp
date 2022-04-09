class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        
        for(int num: nums){
            m[num]++;
        }
        
        for(auto itr=m.begin();itr!=m.end();++itr){
            pq.push({itr->second, itr->first});
        }
        
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};