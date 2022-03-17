class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans=0;
        int pow=0;
        
        for(int i=1;i<S.size();i++){
            if(S[i]=='('){
                pow++;
            } else if(S[i-1]=='('){
                ans += 1<<pow--;
            } else{
                pow--;
            }
        }
        
        return ans;
    }
};