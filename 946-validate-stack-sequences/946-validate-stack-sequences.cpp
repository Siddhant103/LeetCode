class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i=0;
        
        for(int x: pushed){
            stk.push(x);
            while(stk.size()!=0 && stk.top() == popped[i]){
                stk.pop();
                i++;
            }
        }
        
        if(stk.size()==0)
            return true;
        else
            return false;
    }
};