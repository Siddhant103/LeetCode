class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int minSum = INT_MAX;
        int currSum = 0;
        int window = 0;
        
        int n = cardPoints.size();
        int sum = 0;
        for(int i: cardPoints){
            sum += i;
        }
        
        for(int i=0;i<n;i++){
            if(window == n-k){
                minSum = min(minSum, currSum);
                currSum -= cardPoints[i-n+k];
                currSum += cardPoints[i];
            } else{
                window++;
                currSum += cardPoints[i];
            }
        }
        
        minSum = min(minSum, currSum);
        
        return sum - minSum;
    }
};