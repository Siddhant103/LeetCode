class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      int sum=0;
        int n=mat.size();
        for(int i=0;i<mat.size();i++){
            sum+=mat[i][i];
        }
        for(int i=mat.size()-1;i>=0;i--){
            sum+=mat[i][n-1-i];
        }
        if(n%2!=0)
            return sum - mat[mat.size()/2][mat.size()/2];
        else
            return sum;
    }
};   