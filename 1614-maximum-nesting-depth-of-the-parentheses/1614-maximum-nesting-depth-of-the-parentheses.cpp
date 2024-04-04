class Solution {
public:
    int maxDepth(string s) {
        int currCount = 0, maxCount = 0;
        for (char c: s) {
            if (c == '(') {
                currCount++;
                maxCount = max(maxCount, currCount);
            } else if (c == ')'){
                currCount--;
            }
        }

        return maxCount;
    }
};