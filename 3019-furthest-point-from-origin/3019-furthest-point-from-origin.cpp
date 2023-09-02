class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dash = 0, count = 0;
        for (char c: moves) {
            if (c == 'L') {
                count++;
            } else if (c == 'R') {
                count--;
            } else {
                dash++;
            }
        }

        return abs(count) + dash;
    }
};