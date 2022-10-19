class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for(string s: words){
            m[s]++;
        }
        
        auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        
        typedef priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(comp) > my_priority_queue_t;
        my_priority_queue_t  minHeap(comp);
        
        for(auto itr=m.begin(); itr!=m.end();++itr){
            minHeap.push({itr->first, itr->second});
            if(minHeap.size()>k)
                minHeap.pop();
        }
        vector<string> result;
        while(minHeap.size()!=0){
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};