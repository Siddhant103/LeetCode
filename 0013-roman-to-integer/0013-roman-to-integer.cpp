class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanToInteger = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        int number = romanToInteger[s[s.size()-1]];
        
        for(int i=s.size()-2;i>=0;i--){
            if(romanToInteger[s[i]] < romanToInteger[s[i+1]]){
                number -= romanToInteger[s[i]];
            } else{
                number += romanToInteger[s[i]];
            }
        }
        
        return number;
    }
};