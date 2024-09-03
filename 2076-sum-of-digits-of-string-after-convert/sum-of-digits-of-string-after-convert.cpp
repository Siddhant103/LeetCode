class Solution {
    int getSum(string s) {
        int ans = 0;
        for (char ch : s) {
            ans += (int)(ch - '0');
        }
        return ans;
    }
public:
    int getLucky(string s, int k) {
        //convert - O(n)
        string _s = "";
        for (char ch : s) {
            _s += to_string((int)(ch - 'a' + 1));
        }
        //transform - O(n * k)
        while (k-- > 0) {
            _s = to_string(getSum(_s));
        }
        return stoi(_s);
    }
};