class Solution {
public:
    bool match(char start, char end) {
        if ((start == '(' && end == ')') || (start == '[' && end == ']') || (start == '{' && end == '}')) {
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.size() > 0) {
                    char top = st.top();
                    st.pop();
                    if (!match(top, c)) {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        
        if (st.size() !=0) {
            return false;
        }
        return true;
    }
};