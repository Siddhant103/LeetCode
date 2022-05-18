class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor){
            return image;
        }
        
        dfs(image, sr, sc, image.size(), image[0].size(), image[sr][sc], newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int n, int m, int color, int newColor){
        if(sr < 0 || sc < 0 || sr >= n || sc >= m || image[sr][sc] != color){
            return ;
        }
        
        image[sr][sc] = newColor;
        
        dfs(image, sr + 1, sc, n, m, color, newColor);
        dfs(image, sr - 1, sc, n, m, color, newColor);
        dfs(image, sr, sc + 1, n, m, color, newColor);
        dfs(image, sr, sc - 1, n, m, color, newColor);
    }
};