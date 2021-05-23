class Solution {
    int BILLION  = 1000000000;
    int MILLION  = 1000000;
    int THOUSAND = 1000;
public:
    string getStringForHundreds(int n){
        vector<string> less_ten = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        vector<string> less_twenty = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        vector<string> less_hundred = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        
        string s = "";
        if(n != 0){
            int hundred = n/100;
            n %= 100;
            int tenth = n/10;
            int ones = n%10;
            
            if(hundred){
                s += less_ten[hundred] + " Hundred";
            }
            
            if(tenth){
                if(tenth == 1){
                    s += less_twenty[ones];
                    return s;
                }
                else{
                    s += less_hundred[tenth];
                }
            }
            if(ones){
                 s += less_ten[ones];
            }
        }
        
        return s;
        
    }
    
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        string result = "";
        
        if(num/BILLION > 0){
            result += getStringForHundreds(num/BILLION);
            result += " Billion";
            num = num - BILLION * (num/BILLION);
        }
        if(num/MILLION > 0){
            result += getStringForHundreds(num/MILLION);
            result += " Million";
            num = num - MILLION * (num/MILLION);
        }
        if(num/THOUSAND > 0){
            result += getStringForHundreds(num/THOUSAND);
            result += " Thousand";
            num = num - THOUSAND * (num/THOUSAND);
        }
        
        result += getStringForHundreds(num);
        
        return result.substr(1);;
    }
};