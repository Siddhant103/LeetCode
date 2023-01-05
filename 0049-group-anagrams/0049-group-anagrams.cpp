class Solution {
public:
    string calHash(string s) {
        string hash = "";
        vector<int> freq(27, 0);
        for (char c: s) {
            freq[c - 'a']++;
        }
        for (int i=0;i<26;i++) {
            hash += ('a' + i);
            hash += to_string(freq[i]);
        }
        cout << hash << " ";
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> tempMap;
        
        for (string s: strs) {
            string sHash = calHash(s);
            tempMap[sHash].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto m: tempMap) {
            result.push_back(m.second);
        }
        
        return result;
    }
};