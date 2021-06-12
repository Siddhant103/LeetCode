class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        for(int i=0;i<chalk.size();i++){
            sum += chalk[i];
            if(sum > k)
                return i;
        }
        
        k = k % sum;
        int result;
        for(int i=0;i<chalk.size();i++){
            if(k == 0 || k - chalk[i] < 0){
                result = i;
                break;
            }
            
            k = k - chalk[i];
        }
        
        return result;
    }
};