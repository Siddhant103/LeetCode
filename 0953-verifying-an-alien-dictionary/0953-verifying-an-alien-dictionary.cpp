class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> newOrder(26,0);
        
        for(int i=0;i<26;i++){
            newOrder[order[i]-'a'] = i;
        }
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                words[i][j] = newOrder[words[i][j] - 'a']+'a';
            }
            cout<<words[i]<<endl;
        }
        
        for(int i=0;i<words.size();i++)
            cout<<words[i]<<endl;
        
        return is_sorted(words.begin(), words.end());
    }
};