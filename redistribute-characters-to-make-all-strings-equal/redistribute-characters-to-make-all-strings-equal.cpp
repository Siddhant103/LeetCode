class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26, 0);
        for(string word: words){
            for(char c: word){
                count[c - 'a']++;
            }
        }
        int n = words.size();
        
        for(int i=0;i<26;i++){
            if(count[i] % n != 0){
                return false;
            }
        }
        
        return true;
    }
};