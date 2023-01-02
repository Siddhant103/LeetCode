class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(int i=0;i<word.size();i++) {
            if(word[i] >= 65 and word[i] <= 90) cap++;
        }
        if(cap == word.size() or cap == 0) 
            return true;

        if(word[0] >= 65 and word[0] <= 90 and cap ==1) 
            return true;
        return false;
    }
};