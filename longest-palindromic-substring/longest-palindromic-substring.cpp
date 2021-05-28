class Solution {
public:
    int expandAroundCenter(string s, int left, int right){
        
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        
        return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        
        for(int i=0;i<s.size();i++){
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if(len > (right - left)){
                left = i - (len - 1)/2;
                right = i + len/2;
            }
        }
        
        return s.substr(left, right-left+1);
    }
};