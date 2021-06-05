class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0, j = 0, count = 0;
        vector<int> exist(26, 0);
        
        for(char c: source){
            exist[c - 'a'] = 1;
        }
        
        while(j < target.size()){
            cout << j << " ";
            if(exist[target[j] - 'a'] == 0){
                return -1;
            }
            
            if(source[i] == target[j]){
                j++;
            }
            i++;
            
            if(i == source.size()){
                i = 0;
                count++;
            }
            
        }
        
        if(i != 0)
            count++;
        
        return count;
    }
};