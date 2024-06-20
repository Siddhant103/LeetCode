class Solution {
public:
    int ans = INT_MIN;
    bool isPossible(vector<int> positions, int m, int difference) {
        int prev = INT_MIN;
        for(int i = 0; i < positions.size(); i++) 
            if(prev == INT_MIN or positions[i] - prev >= difference) {
                m--;
                prev = positions[i];
            }
        return m <= 0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
		// minimum difference can be 0 and maximum can be the difference of last bucket and the first bucket
        int l = 0, r = position[position.size() - 1] - position[0];
        while(l <= r) {
            int mid = (l + r) / 2;
            if(isPossible(position, m, mid)) {
                ans = max(ans, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};