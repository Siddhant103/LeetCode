class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int count = 0;
        int i = g.size()-1;
        int j = s.size()-1;
        
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                count++;
                i--;
                j--;
            } else{
                i--;
            }
        }
        
        return count;
    }
};
