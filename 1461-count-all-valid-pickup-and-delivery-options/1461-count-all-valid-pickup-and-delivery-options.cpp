class Solution {
public:
    int countOrders(int n) {
	    long count = 1;
	    for(int i=2; i<=n; i++) {
            count = count * (i * (2 * i - 1)) % 1000000007;
        }
	    return count;
    }
};