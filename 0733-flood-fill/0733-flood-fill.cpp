class Solution {
public:
    void fill(vector<vector<int>>& image, int x, int y, int n, int m, int oldColor, int color) {
        if (x < 0 || y < 0 || x >= n || y >= m || image[x][y] == color || image[x][y] != oldColor) {
            return;
        }
        
        image[x][y] = color;
        
        fill(image, x + 1, y, n, m, oldColor, color);
        fill(image, x - 1, y, n, m, oldColor, color);
        fill(image, x, y + 1, n, m, oldColor, color);
        fill(image, x, y - 1, n, m, oldColor, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        fill(image, sr, sc, n, m, image[sr][sc], color);
        return image;
    }
};