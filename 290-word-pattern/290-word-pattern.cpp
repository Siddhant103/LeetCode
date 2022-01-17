class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        unordered_map<string, char> m1;
        unordered_map<char, string> m2;
        int i = 0;
        
        while(ss >> word){
            if(m1.find(word) == m1.end() && m2.find(pattern[i]) == m2.end()){
                m1[word] = pattern[i];
                m2[pattern[i]] = word;
            } else{
                if(m1[word] != pattern[i] || m2[pattern[i]] != word){
                    return false;
                }
            }
            i++;
        }
        
        if(i < pattern.size())
            return false;
        return true;
    }
};