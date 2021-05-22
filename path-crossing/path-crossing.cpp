class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0;
        int y = 0;
        set<string> visit;
        visit.insert(to_string(0) + to_string(0));
        
        for(char c: path){
            if(c == 'N'){
                y++;
            } else if(c == 'E'){
                x++;
            } else if(c == 'S'){
                y--;
            } else{
                x--;
            }
            if(visit.find(to_string(x) + to_string(y)) != visit.end())
                return true;
            
            visit.insert(to_string(x) + to_string(y));
        }
        
        return false;
    }
};