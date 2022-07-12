class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        if(matchsticks.size() < 4 || sum % 4 != 0)
            return false;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        int side = sum / 4;
        vector<int> sides(4, 0);
        
        return isSquare(matchsticks, 0, sides, side);
    }
    
    bool isSquare(vector<int>& matchsticks, int i, vector<int>& sides, int len){
        if(i >= matchsticks.size()){
            return sides[0] == len && sides[1] == len && sides[2] == len && sides[3] == len;
        }
        
        for(int j=0;j<4;j++){
            if(matchsticks[i] + sides[j] > len)
                continue;
            
            sides[j] += matchsticks[i];
            if(isSquare(matchsticks, i + 1, sides, len))
                return true;
            sides[j] -= matchsticks[i];
        }
        
        return false;
    }
    
};