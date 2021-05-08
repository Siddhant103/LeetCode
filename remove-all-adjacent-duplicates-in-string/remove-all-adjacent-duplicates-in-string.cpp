class Solution {
public:
    string removeDuplicates(string S) {
        if(S.size()==0)
            return "";
        stack<char> s;
        s.push(S[0]);
        string result= "";
        for(int i=1;i<S.size();i++){
            if(s.size() && S[i]==s.top()){
                s.pop();
            } else{
                s.push(S[i]);
            }
        }
        while(s.size()){
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};