class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n+1, 0);
        vector<int> suffix(n+1, 0);

        prefix[0] = height[0];
        suffix[n-1] = height[n-1];

        for (int i=1;i<n;i++) {
            prefix[i] = max(prefix[i-1], height[i]);
        }
        // 0 1 1 2 2 2 2 3 3 3 3 3
        for (int i=n-2;i>=0;i--) {
            suffix[i] = max(suffix[i+1], height[i]);
        }
        // 3 3 3 3 3 3 3 3 2 2 2 1
        int sum = 0;
        for (int i=0;i<n;i++) {
            sum += (min(prefix[i], suffix[i]) - height[i]);
        }
        // 0 0 1 0 1 2 1 0 0 1 0 0
        return sum;
    }
};