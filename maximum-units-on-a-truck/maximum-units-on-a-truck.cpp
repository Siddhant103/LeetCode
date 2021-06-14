class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int index = 0, units = 0;
        int n = boxTypes.size();
        
        while(index < n && truckSize){
            if(boxTypes[index][0] <= truckSize){
                truckSize -= boxTypes[index][0];
                units += boxTypes[index][0] * boxTypes[index][1];
            } else{
                units += truckSize * boxTypes[index][1];
                truckSize = 0;
            }
            index++;
        }
        
        return units;
    }
};