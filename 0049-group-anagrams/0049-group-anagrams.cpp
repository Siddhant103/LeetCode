class Solution {
public:
    string getHash(string s){
        vector<int> count(26, 0);
        for(char c: s){
            count[c - 'a']++;
        }
        
        string hash = "";
        for(int i=0;i<26;i++){
            if(count[i] != 0){
                hash += i + 'a';
                hash += to_string(count[i]);
            }
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string s: strs){
            string hash = getHash(s);
            m[hash].push_back(s);
        }
        
        vector<vector<string>> result;
        for(auto itr=m.begin();itr!=m.end();++itr){
            result.push_back(itr->second);
        }
        
        return result;
    }
};