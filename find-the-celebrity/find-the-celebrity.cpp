/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        /*
            If candidate points to something, it can't be a celebrity.
            If the ith person is not pointed to by candidate, i can't be a celebrity.
        */
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) 
                candidate = i;
        }

        /*
            Check that candidate is known by every other person.
            Check that candidate does not know any other person.
        */
        for (int i = 0; i < n; ++i) {
            if (i == candidate) continue;
            if (!knows(i, candidate) || knows(candidate, i)) 
                return -1;
        }
        return candidate;
    }
};