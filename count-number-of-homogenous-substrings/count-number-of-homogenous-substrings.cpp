class Solution {
    int MOD = pow(10, 9) + 7;
public:
    int countHomogenous(string s) {
        
        if(s.size() == 0)
            return 0;
               
        char prev = s[0];
        int size = 1, count = 1;
        
        for(int i=1;i<s.size();i++){            
            if(s[i] == prev){
                size++;
            } else{
                prev = s[i];
                size = 1;
            }
            count = (count + size) % MOD;
        }
        
        return count;
    }
};