class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = 0;
        
        for(int[] account: accounts){
            int sum = 0;
            for(int money: account){
                sum += money;
            }
            maxWealth = Math.max(maxWealth, sum);
        }
        
        return maxWealth;
    }
}