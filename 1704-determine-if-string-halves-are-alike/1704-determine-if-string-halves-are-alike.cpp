class Solution {
public:
    bool checkVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {    
        int n = s.size();
        int vowels=0;
        
        for(int i=0;i<n/2;i++){
            if(checkVowel(s[i]))
                vowels++;
        }
        
        for(int i=n/2;i<n;i++){
            if(checkVowel(s[i]))
                vowels--;
        }
        
        if(vowels==0)
            return true;
        return false;
    }
};