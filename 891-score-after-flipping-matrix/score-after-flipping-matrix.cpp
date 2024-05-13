class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int sum=0;
        int n=grid.size();
        int m=grid[0].size();
        
        sum+=(1<<(m-1))*n;
        for(int j=1;j<m;j++){
            int sbit=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==grid[i][0]){
                    sbit++;
                }
               
            }
            sum+=(1<<(m-j-1))*(max(sbit,n-sbit));
        }
        return sum;
        
        
        
    }
};