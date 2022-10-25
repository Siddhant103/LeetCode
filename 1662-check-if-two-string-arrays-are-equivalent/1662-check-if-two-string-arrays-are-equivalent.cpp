class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "";
        for(string w: word1){
            s1 += w;
        }
        
        string s2 = "";
        for(string w: word2){
            s2 += w;
        }
        
        return s1==s2;
    }
};