class Solution {
public:
    
    bool matches(string word, string pattern){
        vector<char> patternToWord(26,0);
        vector<char> wordToPattern(26,0);
        
        for(int i=0;i<word.size();i++){
            char w = word[i];
            char p = pattern[i];
            if(patternToWord[p-'a'] == 0){
                patternToWord[p-'a'] = w;
            }
            if(wordToPattern[w-'a'] == 0){
                wordToPattern[w-'a'] = p;
            }
            
            if(patternToWord[p -'a'] != w || wordToPattern[w -'a'] != p){
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(string word: words){
            if(matches(word, pattern)){
                result.push_back(word);
            }
        }
        return result;
    }
};