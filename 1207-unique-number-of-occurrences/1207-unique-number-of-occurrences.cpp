class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        
        for (int num: arr) {
            m[num]++;
        }
        
        for (auto item: m) {
            if (s.find(item.second) != s.end()) {
                return false;
            }
            s.insert(item.second);
        }
        
        return true;
    }
};