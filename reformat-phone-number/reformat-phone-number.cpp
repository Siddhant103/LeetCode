class Solution {
public:
    string reformatNumber(string number) {
        string newNumber = "";
        
        for(char c: number){
            if(c == ' ' || c == '-'){
                continue;
            }
            newNumber += c;
        }
        
        int flag = 0;
        flag = newNumber.size() % 3;
            
        string result = "";
        int i = 0;
        
        if(flag == 0){            
            while(i < newNumber.size()){
                result += newNumber.substr(i, 3);
                i += 3;
                result += '-';
            }
        } else if(flag == 2){
            while(i < newNumber.size() - 2){
                result += newNumber.substr(i, 3);
                result += '-';
                i += 3;
            }    
            result += newNumber.substr(i, 2);
            result += '-';
        } else if(flag == 1){
            while(i < newNumber.size() - 4){
                result += newNumber.substr(i, 3);
                result += '-';
                i += 3;
            }    
            result += newNumber.substr(i, 2);
            result += '-';
            i += 2;
            result += newNumber.substr(i, 2);
            result += '-';
        }
        
        return result.substr(0, result.size() - 1);
    }
};