class Solution {
public:
    int minPartitions(string n) {
        char c = '0';
        
        for(char a: n){
            c = max(c, a);
        }
        
        return c - '0';
    }
};