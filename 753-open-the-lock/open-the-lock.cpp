class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadEnds(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        //visited.insert("0000");
        queue<string> q;
        q.push("0000");
        int level = 0;
        
        while(!q.empty()){
            int n = q.size();
            cout << "Q Size = " << n << endl;
            for(int i=0;i<n;i++){
                string pos = q.front(); q.pop();
                
                if(deadEnds.find(pos) != deadEnds.end()){
                    level--;
                    continue;
                }
                if(pos == target){
                    return level;
                }
                
                for(int i=0;i<4;i++){
                    string temp = pos;
                    char c1 = (pos[i] - '0' + 1) % 10 + '0';
                    char c2 = (pos[i] - '0' - 1 + 10) % 10 + '0';
                    
                    temp[i] = c1;
                
                    if(visited.find(temp) == visited.end() && deadEnds.find(temp) == deadEnds.end()){
                        visited.insert(temp);
                        q.push(temp);
                    }
                    temp[i] = c2;
                  
                    if(visited.find(temp) == visited.end() && deadEnds.find(temp) == deadEnds.end()){
                        visited.insert(temp);
                        q.push(temp);
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};