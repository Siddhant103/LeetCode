class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(char c: s){
            m[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto itr=m.begin();itr!=m.end();++itr){
            pq.push({itr->second, itr->first});    
        }
        
        string result = "";
        while(!pq.empty()){
            pair<int, char> temp = pq.top();
            pq.pop();
            int freq = temp.first;
            while(freq--){
                result += temp.second;
            }
        }
        
        return result;
    }
};