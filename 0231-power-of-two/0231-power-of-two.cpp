class Solution {
public:
    bool isPowerOfTwo(int n) {
        long nn = long(n);
        if(nn==0){
            return false;
        }
        
        if(nn==1){
            return true;
        }
        
        if(!(nn & (nn-1)))
            return true;
        
        return false;
    }
};