class Solution {
public:
        vector<vector<int>> minimumAbsDifference(vector<int>& A) {
            //Sort
            sort(A.begin(),A.end());
            
            //List to save result
            vector<vector<int>> result;
            
            int n = A.size(), min = INT_MAX;
            
            for (int i = 1; i < n; i++) {
                int diff = A[i] - A[i - 1];
                if (min == diff) {
                    result.push_back({A[i - 1], A[i]});
                } else if (min > diff) {
                    result.clear();
                    min = diff;
                    result.push_back({A[i - 1], A[i]});
                }
            }
            
            return result;
        }
};