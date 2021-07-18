class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        
        for(int a: arr){
            count[a]++;
        }
        
        unordered_set<int> s;
        for(auto it: count){
            if(s.find(it.second) != s.end()){
                return false;
            }
            s.insert(it.second);
        }
        
        return true;
    }
};