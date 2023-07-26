class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        int count[123]={0};
        for(int i=0;i<s.length();i++){
            count[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(count[t[i]]==0)
                return false;
            else
                count[t[i]]--;
        }
        return true;
    }
};