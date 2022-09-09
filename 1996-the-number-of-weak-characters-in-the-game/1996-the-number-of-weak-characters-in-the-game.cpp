class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    };
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        
        int maxi = INT_MIN;
        int count = 0;
        
        for(int i=0; i<properties.size(); i++){
            if(properties[i][1] < maxi){
                count++;
            }
            else{
                maxi = properties[i][1];
            }
        }
        return count;
    }
};