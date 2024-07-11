class Solution {
public:
    string reverseParentheses(string s) {
        string current = "";
        stack<string> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(current);
                current = "";
            } else if(s[i] == ')'){
                reverse(current.begin(), current.end());
                current = st.top() + current;
                st.pop();
            } else{
                current += s[i];
            }
        }
        
        return current;
    }
};