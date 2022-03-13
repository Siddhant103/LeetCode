class Solution {
public:
    bool matches(char c1, char c2){
        if(c1 == '(' && c2 == ')'){
            return true;
        }
        if(c1 == '[' && c2 == ']'){
            return true;
        }
        if(c1 == '{' && c2 == '}'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> char_stk;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                char_stk.push(s[i]);
            } else{
                if(char_stk.size() == 0 || !matches(char_stk.top(), s[i])){
                    return false;
                }
                char_stk.pop();
            }
        }
        
        if(char_stk.size() != 0)
            return false;
        return true;
    }
};