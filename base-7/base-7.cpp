class Solution {
public:
    string convertToBase7(int num) {
        string result = "";
        if(num == 0)
            return "0";
        int sign = 0;
        if(num < 0){            
            sign = 1;
            num = -num;
        }
        
        while(num){
            result += to_string(num % 7);
            num = num / 7;
        }
        
        reverse(result.begin(), result.end());
        if(sign == 1){
            result = "-" + result;
        }
        return result;
    }
};