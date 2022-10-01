class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0); //dp[x]: stores no of ways to decode string if length is x.
        dp[0] = 1;
        dp[1] = s[0] == '0'? 0 : 1;
        
        for(int i=2;i<=s.size();i++){
            int onesDigit = stoi(s.substr(i-1,1));
            int twosDigit = stoi(s.substr(i-2,2));
            cout<<onesDigit<<" "<<twosDigit<<endl;
            if(onesDigit>=1){
                dp[i]+=dp[i-1];
                cout<<"Entered =1"<<endl;
            }    
            if(twosDigit>=10 && twosDigit<=26){
                dp[i]+=dp[i-2];
                cout<<"Entered =2"<<endl;
            }    
        }
        return dp[s.size()];
    }
};