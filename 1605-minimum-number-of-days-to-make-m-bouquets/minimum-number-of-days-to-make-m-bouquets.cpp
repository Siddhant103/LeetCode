class Solution {
public:
    bool bloomPossibility(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0, noOfBuq = 0;
        for (int bloom: bloomDay) {
            if (bloom <= day) {
                count++;
            } else {
                noOfBuq += (count/k);
                count = 0;
            }
        }
        noOfBuq += (count/k);
        return noOfBuq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        if ((long long)m * k > n) {
            return -1;
        }
        
        int minBloom = INT_MAX, maxBloom = INT_MIN;
        
        for (int bloom: bloomDay) {
            minBloom = min(minBloom, bloom);
            maxBloom = max(maxBloom, bloom);
        }
        int ans = -1;
        while (minBloom <= maxBloom) {
            int mid = minBloom + (maxBloom - minBloom) / 2;
            if (bloomPossibility(bloomDay, mid, m, k)) {
                ans = mid;
                maxBloom = mid - 1;
            } else {
                minBloom = mid + 1;
            }
        }
        
        return ans;
    }
};