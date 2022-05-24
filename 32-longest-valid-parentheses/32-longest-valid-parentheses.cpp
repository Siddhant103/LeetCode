class Solution {
public:
    int longestValidParentheses(string s) {
        
        int ans=0;
        int ret=0;
        
        stack<int> stk;
        
        for(char c: s){
            if (c == ')'){
                if (stk.size() > 0) {
                    ans = ans + 1 + stk.top();
                    stk.pop();
                    
                    ret = max(ret, ans);
                } else {
                    ans = 0;
                }
            } else {
                stk.push(ans + 1);
                ans = 0;
            }
        }
        
        return ret;
        
    }
};