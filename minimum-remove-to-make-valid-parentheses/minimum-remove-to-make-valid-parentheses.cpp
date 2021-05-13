class Solution {
public:
    string modifyString(string s, int balance){
        cout<<"\nEntered modifyString:"<<endl;
        for(int i=s.size()-1;i>=0 && balance!=0;i--){
            if(s[i] == '('){
                string newString = s.substr(0,i) + s.substr(i+1);
                cout<<"Shrinking string at i: "<<i<<endl;
                s = newString;
                i++;
                balance--;
            }    
        }
        return s;
    }
    string minRemoveToMakeValid(string s) {
        int balance = 0;
        
        for(int i=0;i<s.size();i++){
            cout<<s.size()<<" "<<endl;
            if(s[i] == '('){
                balance++;
            } else if(s[i] == ')'){
                balance--;
            }
            if(balance<0){
                cout<<"Shrinking string at i: "<<i<<endl;
                string newString = s.substr(0,i) + s.substr(i+1);
                s = newString;
                balance = 0;
                i--;
            }
        }
        if(balance == 0)
            return s;
        return modifyString(s, balance);
    }
};