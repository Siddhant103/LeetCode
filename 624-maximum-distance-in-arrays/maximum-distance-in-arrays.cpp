class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxTillNow = INT_MIN, minTillNow = INT_MAX;
        int maxDistTillNow = 0;

        for (const auto& array : arrays) {
            int len = array.size();
            int firstEle = array[0], lastEle = array[len - 1];

            if (maxTillNow == INT_MIN) {
                maxTillNow = max(maxTillNow, lastEle);
                minTillNow = min(minTillNow, firstEle);
                continue;
            }

            int firstEleDist = max(abs(maxTillNow - firstEle), abs(minTillNow - firstEle));
            int lastEleDist = max(abs(maxTillNow - lastEle), abs(minTillNow - lastEle));
            int currDist = max(firstEleDist, lastEleDist);

            maxDistTillNow = max(currDist, maxDistTillNow);
            maxTillNow = max(maxTillNow, lastEle);
            minTillNow = min(minTillNow, firstEle);
        }

        return maxDistTillNow;
    }
};