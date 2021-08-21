class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wList(wordList.begin(), wordList.end());
        
        if(wList.find(endWord) == wList.end())
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        
        while(!q.empty()){
            int n = q.size();
            level++;
            while(n--){
                string curr = q.front(); q.pop();
                for(int i=0;i<curr.size();i++){
                    string temp = curr;
                    for(char c = 'a' ; c <= 'z' ; c++){
                        temp[i] = c;
                        if(temp == curr)
                            continue;
                        if(temp == endWord)
                            return level + 1;
                        if(wList.find(temp) != wList.end()){
                            q.push(temp);
                            wList.erase(temp);
                        }
                    }
                }
            }
            
        }
        
        return 0;
    }
};