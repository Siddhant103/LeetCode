class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), comp);
        
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= result[result.size()-1][1]){
                vector<int> temp = {result[result.size()-1][0], max(intervals[i][1], result[result.size()-1][1])};
                result.pop_back();
                result.push_back(temp);
            } else{
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};