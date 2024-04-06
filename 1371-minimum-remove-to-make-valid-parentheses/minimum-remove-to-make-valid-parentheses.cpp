class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(i);
            } 
            if(s[i]==')'){
                if(!stk.empty()){
                    stk.pop();
                } else{
                    s.erase(i--, 1);
                }
            }
        }
        while(!stk.empty()){
            s.erase(stk.top(),1);
            stk.pop();
        }
        
        return s;
    }
};