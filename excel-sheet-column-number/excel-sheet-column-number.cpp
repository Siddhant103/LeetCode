class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int result = 0;
        int n = columnTitle.size();
        int i = 0;
        while(i < n){
            result = result * 26 + (columnTitle[i] - 'A' + 1);
            i++;
        }
        
        return result;
    }
};