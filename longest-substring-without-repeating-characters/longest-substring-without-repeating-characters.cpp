class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> occurs;
        int maxLen = 0;
        int start = -1;
        int index = 0;
        
        while(index < s.size()){
            if(occurs.count(s[index]) != 0){
                start = max(start, occurs[s[index]]);
            }
            occurs[s[index]] = index;
            maxLen = max(maxLen, index - start);
            index++;
        }
        
        return maxLen;
    }
};
