class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0;
        unordered_set<string> s(words.begin(), words.end());
        
        for(string w: s){
            for(int i=1;i<w.size();i++){
                s.erase(w.substr(i));
            }
        }
        for(string w: s){
            ans += w.length()+1;
        }
        
        return ans;
    }
};