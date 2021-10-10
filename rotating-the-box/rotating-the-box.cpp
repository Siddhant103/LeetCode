class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        for(int i = 0; i < m; i++) {
            int prev = n;
            int j = prev - 1;
            while(j >= 0) {
                while(j >= 0 && box[i][j] != '*') --j;
                sort(box[i].begin() + j + 1, box[i].begin() + prev);
                reverse(box[i].begin() + j + 1, box[i].begin() + prev);
                prev = j;
                --j;
            }
        }
        vector<vector<char > > ans(n, vector<char>(m));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[j][i] = box[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m/2; j++) {
                swap(ans[i][j], ans[i][m - j - 1]);
            }
        }
        return ans;
    }
};