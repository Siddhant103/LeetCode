class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        /*
            Keeping a window of size of n-k and calculating sum of all elements - sum(n-k) for each window
        */
        
        int n = cardPoints.size();
        int totalSum = 0;
        
        for(int points: cardPoints){
            totalSum += points;
        }
        // 1,2,3,4,5,6,1    k=3;
        int minScore = INT_MAX;
        int window = 0;
        int currScore = 0;
        
        for(int i=0;i<cardPoints.size();i++){
            if(window == n-k){
                minScore = min(minScore, currScore);
                currScore -= cardPoints[i-n+k];
                currScore += cardPoints[i];
            } else{
                window++;
                currScore += cardPoints[i];
            }
        }
        minScore = min(minScore, currScore);
        
        return totalSum - minScore;
    }
};