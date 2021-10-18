class Solution {
public:
    bool isMatch(char c1, char c2){
        return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
    }
    
    bool isValid(string s) {
        stack<char> stk;
        
        if(s.size() == 0)
            return true;
        
        stk.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
            } else{
                if(stk.size() == 0 || !isMatch(stk.top(), s[i])){
                    return false;
                }
                stk.pop();
            }
        }
        
        if(stk.size()!=0)
            return false;
        return true;
    }
};