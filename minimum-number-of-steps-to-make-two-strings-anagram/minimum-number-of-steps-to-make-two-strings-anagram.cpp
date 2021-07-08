class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count1(26, 0);
        for(char c: s){
            count1[c - 'a']++;
        }
        
        vector<int> count2(26, 0);
        for(char c: t){
            count2[c - 'a']++;
        }
        
        int count = 0;
        
        for(int i=0;i<26;i++){
            count += abs(count1[i] - count2[i]);
        }
        
        return count/2;
    }
};