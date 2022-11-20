class Solution {
public:
    bool isnum(char c) { return c >= '0' && c <= '9'; }
    int cal (vector<vector<int>> &nums, vector<vector<int>> &ops) {
        for (int i = ops.back().size() - 1, j = nums.back().size() - 1; i >= 0; i--, j--)
            nums.back()[j] *= ops.back()[i];
        int num = accumulate(begin(nums.back()), end(nums.back()), 0);
        nums.pop_back();
        ops.pop_back();
        return num;
    } 
    int calculate(string s) {
        vector<vector<int>> nums{{}};
        vector<vector<int>> ops{{}};
        int n = s.size(), sign = 1;
        for(int i = 0; i < n; i++) {            
            if (isnum(s[i])) {
                int num = 0;
                for (; i < n && isnum(s[i]); i++)
                    num = num * 10 + (s[i] - '0');
                nums.back().push_back(num * sign);
            }
            
            if (s[i] == '+') ops.back().push_back(1);
            if (s[i] == '-') ops.back().push_back(-1);
            
            if (s[i] == '(') {
                nums.push_back({});
                ops.push_back({});
            } 
            if (s[i] == ')') {
                int tmp = cal(nums, ops);
                nums.back().push_back(tmp);
            }
        }
        return cal(nums, ops);
    }
};