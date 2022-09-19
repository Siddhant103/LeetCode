class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string, vector<string>> store;
        vector<vector<string>> result;
        
        //["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
        
        for(string path: paths){
            stringstream ss(path);
            string word;
            ss >> word;
            string directory = word;
            while(ss >> word){
                int index = word.find('(');
                string fileName = word.substr(0, index);
                string content = word.substr(index+1, word.size()-index-2);
                string tempDir = directory;
                tempDir += "/";
                tempDir += fileName;
                store[content].push_back(tempDir);
                cout<< fileName <<" " << tempDir<<endl;
            }
        }
        
        
        int i=0;            
        for(auto itr=store.begin(); itr!=store.end(); ++itr){
            if(itr->second.size()>1){
                result.push_back(itr->second);
            }
        }
        
        return result;
    }
};