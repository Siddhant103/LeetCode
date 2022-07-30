class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> count(26);
        vector<int> temp(26);
        int i;
        
        for(string b: B){
            temp = countChars(b);
            for(i=0;i<26;i++){
                count[i] = max(count[i], temp[i]);
            }
        }
        
        vector<string> ans;
        for(string s: A){
            temp = countChars(s);
            for(i=0;i<26;i++){
                if(temp[i]<count[i])
                    break;
            }
            if(i==26)
                ans.push_back(s);
        }
        
        return ans;
    }
    
    vector<int> countChars(string s){
        vector<int> ans(26);
        for(char c: s){
            ans[c-'a']++;
        }
        return ans;
    }
};