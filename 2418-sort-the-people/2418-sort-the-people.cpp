class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> m;
        for (int i=0;i<names.size();i++) {
            m[heights[i]] = names[i];
        }
        
        int size = names.size();
        
        for (auto it=m.begin();it!=m.end();it++) {
            names[--size] = it->second;
        }
        
        return names;
    }
};