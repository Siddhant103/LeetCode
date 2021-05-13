class Solution {
public:
    
    bool isChar(char c){
        if((c>=65 && c<=90) || (c>=97 && c<=122) || (c>=48 && c<=57))
            return true;
        return false;
    }
    
    bool areSame(char c1, char c2){
        cout<<c1<<" "<<c2<<endl;
        if(c1>=65 && c1<=90){
            c1 += 32;
        }
        if(c2>=65 && c2<=90){
            c2 += 32;
        }
        
        return c1 == c2;
    }
    bool isPalindrome(string s) {
        
        int left = 0;
        int right = s.size()-1;
        
        while(left<right){
            if(!isChar(s[left])){
                left++;
                continue;
            }
            if(!isChar(s[right])){
                right--;
                continue;
            }
            if(!areSame(s[left], s[right])){
                return false;
            }
            left++;
            right--;
        }
        
        return true;
        
    }
};