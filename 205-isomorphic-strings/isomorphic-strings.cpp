class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        unordered_map<char, char> m;
        unordered_map<char, char> n;
        
        for(int i=0;i<s.size();i++) {
            if (m[s[i]] != n[t[i]])
                return false;
            
            m[s[i]] = i+1;
            n[t[i]] = i+1;
        }
        return true;
    }
};