class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        if(matrix.size()==0)
            return ans;
        
        int rowBegin = 0;
        int rowEnd = matrix.size()-1;
        int colBegin = 0;
        int colEnd = matrix[0].size()-1;
        
        cout<<rowEnd<<endl;
        cout<<colEnd<<endl;
        //exit(0);
        
        while(rowBegin <=rowEnd && colBegin <= colEnd){
            cout<<rowBegin<<endl;
            cout<<colBegin<<endl;
            for(int i=colBegin;i<=colEnd;i++){
                ans.push_back(matrix[rowBegin][i]);
            }
            rowBegin++;
            //continue;
            for(int i=rowBegin;i<=rowEnd;i++){
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            if(rowBegin<=rowEnd){
                for(int i=colEnd;i>=colBegin;i--)
                    ans.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            
            if(colBegin<=colEnd){
                for(int i=rowEnd;i>=rowBegin;i--){
                    ans.push_back(matrix[i][colBegin]);
                }
            }
            colBegin++;
        }
        
        return ans;
    }
};