class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int age[101] = {0};
        for(vector<int> log: logs){
            age[log[0] - 1950]++;
            age[log[1] - 1950]--;
        }
        
        int count = 0, year;
        int maxPopulation = 0;
        for(int i=0;i<101;i++){
            count += age[i];
            if(count > maxPopulation){
                maxPopulation = count;
                year = i;
            }
        }
        
        return year + 1950;
    }
};