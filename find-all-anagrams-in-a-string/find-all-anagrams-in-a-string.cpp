class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> p_count(26,0), s_count(26,0);
        vector<int> result;
        
        if(p.size()>s.size())
            return result;
        for(int i=0;i<p.size();i++){
            p_count[p[i]-'a']++;
            s_count[s[i]-'a']++;
        }
        
        if(p_count == s_count){
            result.push_back(0);
        }
        
        for(int i=p.size();i<s.size();i++){
            s_count[s[i]-'a']++;
            s_count[s[i-p.size()]-'a']--;
            if(s_count == p_count){
                result.push_back(i-p.size()+1);
            }
        }
        
        return result;
    }
};