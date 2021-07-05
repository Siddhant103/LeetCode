class Solution {
public:
    unordered_map<string, bool> dict;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        return wordBreakRecursive(s, wordDict);
    }
    
    bool wordBreakRecursive(string s, vector<string>& wordDict){
        if(dict.find(s) != dict.end()){
            return dict[s];
        }
        
        if(s == ""){
            return true;
        }
        
        string prev = s;
        for(int i=0;i<wordDict.size();i++){
            if(s.find(wordDict[i]) == 0){
                s = s.substr(wordDict[i].size(), s.size());
                if(wordBreakRecursive(s, wordDict)){
                    return true;
                }
                
                s = prev;
            }
        }
        
        dict[s] = false;
        return dict[s];
    }
};