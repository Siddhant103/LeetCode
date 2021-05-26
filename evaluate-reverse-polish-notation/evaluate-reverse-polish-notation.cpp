class Solution {
public:
    bool isOperand(string token){
        if(token == "+" || token == "-" || token == "*" || token == "/")
            return true;
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(string token: tokens){
            if(isOperand(token)){
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                if(token == "+"){
                    s.push(x + y);
                } else if(token == "-"){
                    s.push(x - y);
                } else if(token == "*"){
                    s.push(x * y);
                } else if(token == "/"){
                    s.push(x / y);
                }
            } else{
                s.push(stoi(token));
            }
        }
        
        return s.top();
    }
};