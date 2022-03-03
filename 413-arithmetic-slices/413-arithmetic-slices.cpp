class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n,0);
        
        if(n<3)
            return 0;
        
        int result = 0;
        
        if(A[2]-A[1] == A[1]-A[0])
            ans[2]=1;
        
        result = ans[2];
        
        for(int i=3;i<n;i++){
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
                ans[i]=ans[i-1]+1;
            
            result+=ans[i];
        }
        
        return result;
    }
};