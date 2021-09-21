class Solution {
public:
    int maxPower(string s) {
        int power = 0;
        int i=0, curr = 0;
        char c = ' ';
        while(i < s.size()){
            if(s[i] == c){
                curr++;
            } else{
                power = max(power, curr);
                curr = 1;
                c = s[i];
            }
            i++;
        }
        power = max(power, curr);
        return power;
    }
};