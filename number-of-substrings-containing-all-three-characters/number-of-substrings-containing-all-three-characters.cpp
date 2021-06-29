class Solution {
public:
    int numberOfSubstrings(string s) {
        int start = 0;
        int end = 0;
        int count = 0;
        int n = s.size();
        vector<int> c(3,0);
        
        while(end < n){
            c[s[end] - 'a']++;
            if(c[0] > 0 && c[1] > 0 && c[2] > 0){
                count += (n - end);
                c[s[end] - 'a']--;
                c[s[start] - 'a']--;
                start++;
            } else{
                end++;
            }
        }
            
        return count;
    }
};