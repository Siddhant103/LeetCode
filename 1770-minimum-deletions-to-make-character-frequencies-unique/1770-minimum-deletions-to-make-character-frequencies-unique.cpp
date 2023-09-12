class Solution {
public:
    int minDeletions(string s) {
       int n = s.size();
        unordered_map<char,int>mp;
        int ans=0;
        set<int>st;
        
        for(char c: s)
            mp[c]++;

        for (auto[i,j] :mp) {
            while(st.find(j) != st.end()) {
                j--;
                ans++;
            }
            if (j > 0) {
                st.insert(j); 
            }
        }

        return ans;
    }
};