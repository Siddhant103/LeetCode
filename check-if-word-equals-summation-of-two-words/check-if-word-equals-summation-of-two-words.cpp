class Solution {
public:
    int getNumericalValue(string s){
        int num = 0;
        for(char c: s){
            num = num * 10 + (c - 'a');
        }
        return num;
    }
    
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        int numValFirst = getNumericalValue(firstWord);
        int numValSecond = getNumericalValue(secondWord);
        int numValTarget = getNumericalValue(targetWord);
        
        if(numValFirst + numValSecond == numValTarget){
            return true;
        }
        
        return false;
    }
};