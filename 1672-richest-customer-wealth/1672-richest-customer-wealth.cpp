class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        
        for(int i=0;i<accounts.size();i++){
            int sum=0;
            for(auto money: accounts[i]){
                sum+=money;
            }
            maxWealth = max(maxWealth, sum);
        }
        return maxWealth;
    }
};