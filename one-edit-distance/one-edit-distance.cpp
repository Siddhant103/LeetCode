class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        /*
            3 Cases
            1. Same length -> iterate over both and see the no of differnces(if greater than 1 return false else true)
            2. s length greater than t ->iterate again and see the point of differnce(in this case iterate over the longer string)
            3. t length greater than s -> same as case 2
        */
        
        int m = s.size();
        int n = t.size();
        
        if(m > n){
            return isOneEditDistance(t, s);
        }
        
        for(int i=0;i<min(m, n);i++){
            if(s[i] != t[i]){
                if(m == n){
                    return s.substr(i+1) == t.substr(i+1);
                } else{
                    return s.substr(i) == t.substr(i+1);
                }
            }
        }
        
        return (m+1 == n) || (m == n+1);
    }
};