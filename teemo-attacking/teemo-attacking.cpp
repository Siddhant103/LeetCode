class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int count = 0;
        int n = timeSeries.size();
        
        count = duration;
        int coveredTill = timeSeries[0] + duration - 1;
        
        for(int i = 1; i < timeSeries.size(); i++){
            if(timeSeries[i] > coveredTill){
                count += duration;
            } else{
                count = count - (coveredTill - timeSeries[i] + 1);
                count += duration;                
            }
            coveredTill = timeSeries[i] + duration - 1;
        }
        
        return count;
    }
};