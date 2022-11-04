class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            return true;
        }
        return false;
    }
    
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        
        while(left < right){
            if(!isVowel(s[left])){
                left++;
                continue;
            }
            if(!isVowel(s[right])){
                right--;
                continue;
            }
            if(isVowel(s[left]) && isVowel(s[right])){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
        
        return s;
    }
};