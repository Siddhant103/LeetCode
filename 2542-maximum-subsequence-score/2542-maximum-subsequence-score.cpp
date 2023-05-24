class Solution {
public:
    long long maxScore(vector<int> &n1, vector<int> &n2, int k) {
        // support variables
        int len = n1.size(), currVal1, idx[len], r = 0, currIdx;
        long long currSum = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> usedN1s;
        // populating idx
        iota(idx, idx + len, 0);
        sort(idx, idx + len, [&n2](int a, int b){return n2[a] > n2[b];});
        // getting the k highest values in n2
        while (k--) {
            currIdx = idx[r++];
            currVal1 = n1[currIdx];
            currSum += currVal1;
            usedN1s.push(currVal1);
        }
        // base res computed with the first highest k n2 elements
        res = currSum * n2[idx[r - 1]];
        // parsing the rest of pq to find anything better
        while (r < len) {
            // removing the least element previously added in currSum
            currSum -= usedN1s.top(), usedN1s.pop();
            // following the same logic of the previous loop
            currIdx = idx[r++];
            currVal1 = n1[currIdx];
            currSum += currVal1;
            usedN1s.push(currVal1);
            // updating res
            res = max(res, currSum * n2[currIdx]);
        }
        return res;
    }
};