class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> counts(124,0);
        int len = 0;
        int odd = 0;
        
        for(char c: s){
            counts[c]++;
        }
        
        for(int i=0;i<124;i++){
            if(counts[i]>0)
            cout<<counts[i]<<" ";
            if(counts[i]%2==0)
                len += counts[i];
            else if(counts[i]%2!=0){
                len += (counts[i]>1? counts[i]-1:0);
                odd=1;
            }
        }
        
        return len + odd;
    }
};