class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> result;
        int i, j, k;
        int K = 0; // Making the question generic, 3 numbers sum should be K

        for (int k=0;k<n-1;k++) {
            i = k + 1;
            j = n - 1;
            while (i < j) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < K) {
                    // Sum is lesser so we move poiter from smaller -> bigger number
                    i++;
                } else if (sum > K) {
                    // Sum is greater so we move poiter from bigger -> smaller number
                    j--;
                } else {
                    // Equality Codition
                    result.push_back({arr[i], arr[j], arr[k]});
                    i++;
                    j--;
                    // Skipping same number as ith index
                    while (i < j && arr[i - 1] == arr[i]) {
                        i++;
                    }
                    // Skipping same number as jth index
                    while (i < j && arr[j + 1] == arr[j]) {
                        j--;
                    }
                }
            }
            // Skipping same number as kth index
            while (k < n - 1 && arr[k] == arr[k + 1]) {
                k++;
            }
        }

        return result;
    }
};