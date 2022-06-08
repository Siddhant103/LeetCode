class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)
            return 0;
        
        string b=s;
        reverse(b.begin(),b.end());
        
        if(b==s)
            return 1;
        return 2;
    }
};