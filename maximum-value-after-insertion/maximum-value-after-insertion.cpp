class Solution {
public:
    string maxValue(string n, int x) {
        /*
        Example 1:

        Input: n = "99", x = 9
        Output: "999"
        Explanation: The result is the same regardless of where you insert 9.
        Example 2:

        Input: n = "-13", x = 2
        Output: "-123"
        Explanation: You can make n one of {-213, -123, -132}, and the largest of those three is -123.
        */
        int i = 0;
        if(n[0] != '-'){
            while(i < n.size() && n[i] - '0' >= x){
                i++;
            }
            cout << i << endl;
            cout << n.substr(0, i) << endl;
            n = n.substr(0, i) + to_string(x) + (i < n.size() ? n.substr(i) : "");
            return n;
        }
        
        n = n.substr(1);
        cout << n << endl;
        
        while(i < n.size() && n[i] - '0' <= x){
            i++;
        }
        
        cout << i << endl;
        cout << n.substr(0, i) << endl;
        n = n.substr(0, i) + to_string(x) + (i < n.size() ? n.substr(i) : "");
        return "-" + n;
    }
};