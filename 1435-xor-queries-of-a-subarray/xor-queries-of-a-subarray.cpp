class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v;
        for(int i = 1; i < arr.size(); i++){
            arr[i] = arr[i]^arr[i-1];
        }
        for(auto i: queries){
            int start = i[0], end = i[1];
            if(start==0)
                v.push_back(arr[end]);
            else
                v.push_back(arr[start-1]^arr[end]);
        }
        return v;
    }
};