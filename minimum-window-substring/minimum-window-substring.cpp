class Solution {
public:
    string minWindow(string s, string t) {
        /*
        Example 1:

        Input: s = "ADOBECODEBANC", t = "ABC"
        Output: "BANC"
        Example 2:

        Input: s = "a", t = "a"
        Output: "a"
        
        */
        if(s.size() == 0 || t.size() == 0){
            return "";
        }
        unordered_map<char, int> p;
        
        for(char c: t){
            p[c]++;
        }
        
        int i = 0, j = 0;
        int minLen = s.size();
        int count = p.size();
        int left = 0, right = s.size()-1;
        bool found = false;
        
        while(j<s.size()){
            
            char jChar = s[j++];
            if(p.find(jChar) != p.end()){
                p[jChar]--;
                if(p[jChar] == 0)
                    count--;
            }
            
            if(count > 0)
                continue;
            
            while(count == 0){
                char iChar = s[i++];
                if(p.find(iChar) != p.end()){
                    p[iChar]++;
                    if(p[iChar] > 0)
                        count++;
                }   
            }
            
            if((j - i) < minLen){
                left = i;
                right = j;
                minLen = j - i;
                found = true;
            }
        }
        
        return !found ? "" : s.substr(left-1, right-left+1);
    }
};