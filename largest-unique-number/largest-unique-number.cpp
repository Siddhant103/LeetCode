class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        vector<int> count(1001,0);
        
        for(int a: A){
            count[a]++;
        }
        
        for(int i=1000;i>=0;i--){
            if(count[i]==1)
                return i;
        }
        
        return -1;
    }
};