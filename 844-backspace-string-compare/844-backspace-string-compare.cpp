class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int s_ptr = S.size()-1;
        int t_ptr = T.size()-1;
        int s_skips=0;
        int t_skips=0;
        while(s_ptr>=0 || t_ptr>=0){
            if(s_ptr>=0 && S[s_ptr]=='#'){
                cout<<"1 ";
                s_ptr--;
                s_skips++;
            } else if(s_skips){
                cout<<"2 ";
                s_ptr--;
                s_skips--;
            } else if(t_ptr>=0 && T[t_ptr]=='#'){
                cout<<"3 ";
                t_ptr--;
                t_skips++;
            } else if(t_skips){
                t_ptr--;
                t_skips--;
                cout<<"4 ";
            } else if(s_ptr<0 || t_ptr<0 || S[s_ptr]!=T[t_ptr]){
                cout<<"5 ";
                return false;
            } else{
                cout<<"6 ";
                s_ptr--;
                t_ptr--;
            }
            cout<<endl;
        }
        return true;
    }
};