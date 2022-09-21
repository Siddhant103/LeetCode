class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        
        int sum=0;
        for(int a: A){
            if(a%2==0)
                sum+=a;
        }
        
        for(int i=0;i<queries.size();i++){
            int value = queries[i][0];
            int index = queries[i][1];
            if(A[index]%2==0)
                sum -= A[index];
            A[index] += value;
            if(A[index]%2==0)
                sum += A[index];
            ans.push_back(sum);
        }
        
        return ans;
    }
};