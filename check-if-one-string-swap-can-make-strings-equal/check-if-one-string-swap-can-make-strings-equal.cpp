class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() == 0)
            return true;
        int count = 0;
        vector<int> mismatch;
        
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]){
                mismatch.push_back(i);
            }
            
            if(mismatch.size() > 2)
                return false;
        }
        
        if(mismatch.size() == 0)
            return true;
        if(mismatch.size() == 2){
            swap(s1[mismatch[0]], s1[mismatch[1]]);
            return s1 == s2;
        }
            
        return false;
    }
};