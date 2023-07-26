class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return 0;
        
        s += s;
        
        if (s.find(goal) != -1)
            return true;
        
        return false;
    }
};