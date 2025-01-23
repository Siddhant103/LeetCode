class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int n = name.size();
        int m = typed.size();
        for(int j=0;j<m;j++){
            if(i<n && name[i] ==typed[j]){
                i++;
            }
            else if(!j || typed[j]!=typed[j-1]) return false;
        }
        if(i == n) return true;
        return false;
    }
};