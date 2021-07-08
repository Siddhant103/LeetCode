class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count1(26, 0);
        for(char c: s){
            count1[c - 'a']++;
        }
        
        for(char c: t){
            count1[c - 'a']--;
        }
        
        int count = 0;
        
        for(int i=0;i<26;i++){
            if(count1[i] < 0)
                count += -count1[i];
        }
        
        return count;
    }
};