class Solution {
public:
    
    int ans=1;
    void helper(string &str,int ind,vector<string> &temp,unordered_set<string> &st)
    {
        if(ind == str.length()){
            
            int l=temp.size();
            ans = max(ans,l);
            return;
        }
        string s="";
        for(int i=ind;i<str.length();i++){
            s.push_back(str[i]);
            if(!st.count(s)){                              // call only when string s is not in our set or s is not repeated.
                temp.push_back(s);
                st.insert(s);
                helper(str,i+1,temp,st);
                st.erase(s);                         // backtrack
                temp.pop_back();                     // backtrack 
            }
        }
    }
    int maxUniqueSplit(string s) {
        
        vector<string> temp;
        unordered_set<string> st;
        helper(s,0,temp,st);
        return ans;
        
    }
};