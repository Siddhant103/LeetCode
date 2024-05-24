class Solution {
public:
    int maxScore = INT_MIN;
    void f(int idx,vector<string>&words,vector<int>&freq,int currScore,vector<int>&score) {
        maxScore = max(maxScore,currScore);
        if(idx>=words.size()) {
            return;
        }
        //take
        string str = words[idx];
        vector<int>tempFreq = freq;
        int i = 0;
        int tempScore = 0;
        while(i<str.length()) {
            tempFreq[str[i]-'a']--;
            tempScore += score[str[i]-'a'];
            if(tempFreq[str[i]-'a']<0) {
                break;
            }
            i++;
        }
        if(i==str.length()) {
            f(idx+1,words,tempFreq,tempScore+currScore,score);
        }
        //notTake
        f(idx+1,words,freq,currScore,score);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>vec(26,0);
        for(int i=0;i<letters.size();i++) {
            vec[letters[i]-'a']++;
        }
        f(0,words,vec,0,score);
        return maxScore;
    }
};