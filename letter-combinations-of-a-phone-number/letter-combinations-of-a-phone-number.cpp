class Solution {
public:
    void backtrack(string digits, int i, string current, const vector<string>& numpad, vector<string>& result){
        if(i == digits.size()){
            result.push_back(current);
            return;
        }
        
        for(char c: numpad[digits[i] - '0']){
            backtrack(digits, i + 1, current + c, numpad, result);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        
        vector<string> result;
        string current = "";
        const vector<string> numpad = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        backtrack(digits, 0, current, numpad, result);
        return result;
    }
};