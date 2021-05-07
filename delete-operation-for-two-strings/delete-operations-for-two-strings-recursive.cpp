class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.size();
        int col = word2.size();
        
        int lcs = lcSubsequence(word1, word2, row, col);
        cout<<lcs;
        
        return word1.size() + word2.size() - 2*lcs;
    }
    
    int lcSubsequence(string word1, string word2, int m, int n){
        if(m==0 || n==0)
            return 0;
        
        if(word1[m-1]==word2[n-1]){
            return lcSubsequence(word1, word2, m-1, n-1) + 1;
        }
        
        return max(lcSubsequence(word1, word2, m-1, n), lcSubsequence(word1, word2, m, n-1));
    }
};
