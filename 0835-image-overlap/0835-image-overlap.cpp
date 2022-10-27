class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> v, p;
        for (int i = 0; i < img1.size(); ++i) {
            for (int j = 0; j < img1[0].size(); ++j) {
                if (img1[i][j] == 1) {
                    v.push_back({i,j});
                }
            }
        }
        for (int i = 0; i < img2.size(); ++i) {
            for (int j = 0; j < img2[0].size(); ++j) {
                if (img2[i][j] == 1) {
                    p.push_back({i,j});
                }
            }
        }
        
        map<pair<int,int>,int>m;
        for (auto i : v) {
            for (auto k : p) {
                m[{i.first - k.first, i.second - k.second}]++;
            }
        }
        
        int cnt = INT_MIN;
        for (auto i : m) {
            cnt = max(cnt,i.second);
        }
        return cnt == INT_MIN ? 0 : cnt;
    }
};