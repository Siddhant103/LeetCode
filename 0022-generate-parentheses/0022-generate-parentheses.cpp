class Solution {
public:
    void generate(int n, int l, int r, string curr, vector<string>& result){
        if(l == n && r == n){
            result.push_back(curr);
            return;
        }
        
        if(l < n){
            generate(n, l + 1, r, curr + "(", result);
        }
        if(r < l){
            generate(n, l, r + 1, curr + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }
};