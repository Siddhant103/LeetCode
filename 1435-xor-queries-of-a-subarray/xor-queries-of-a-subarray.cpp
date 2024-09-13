class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> v;
        int k = 0;
        for(auto i: queries){
            for(int j = i[0]; j <= i[1]; j++){
                k = k^arr[j];
            }
            v.push_back(k);
            k = 0;
        }
        return v;
    }
};