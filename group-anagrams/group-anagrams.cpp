class Solution {
public:
    
    string getHashCode(string a){
        vector<int> count(26, 0);
        for(char c: a){
            count[c - 'a']++;
        }
        
        string outputHash = "";
        
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                outputHash += (i+'a');
                outputHash += to_string(count[i]);
            }
        }
        
        return outputHash;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hashCodes;
        
        for(string s: strs){
            string hash = getHashCode(s);
            cout<<hash<<endl;
            if(hashCodes.find(hash)!=hashCodes.end()){
                hashCodes[hash].push_back(s);
            } else{
                vector<string> temp;
                temp.push_back(s);
                hashCodes.insert({hash, temp});
            }
        }
        
        for(auto itr=hashCodes.begin();itr!=hashCodes.end();++itr){
            result.push_back(itr->second);
        }
        
        return result;
    }
};