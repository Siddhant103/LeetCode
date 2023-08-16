class Solution {
public:
    // string longestPalindrome(string s) {
        
    //     int start = 0, end = 0;
    //     int len;
    //     for(int i=0;i<s.size();i++){
    //         int len1 = expandAroundCenter(s, i, i);
    //         int len2 = expandAroundCenter(s, i, i+1);
    //         len = max(len1, len2);
    //         if(len>end-start){
    //             start = i-(len-1)/2;
    //             end = i+len/2;
    //         }
    //     }
    //     string result;
    //     for(int i=start;i<=end;i++)
    //         result += s[i];
    //     return result;
    // }
    
    // int expandAroundCenter(string s, int left, int right){
        
    //     while(left>=0 && right<s.size() && s[left] == s[right]){
    //         left--;
    //         right++;
    //     }
        
    //     return right-left-1;
    // }

    int expandAroundCenter(string s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - i - 1;
    }

    string longestPalindrome(string s) {
        
        int start = 0, end = 0;
        for (int i=0;i<s.size();i++) {
            int s1 = expandAroundCenter(s, i, i);
            int s2 = expandAroundCenter(s, i, i + 1);
            int len = max(s1, s2);
            if (len > end - start) {
                start = i - (len-1) / 2;
                end = i + len/2;
            }
        }
        string result = "";

        for (int i=start;i<=end;i++) {
            result += s[i];
        }

        return result;
    }
};