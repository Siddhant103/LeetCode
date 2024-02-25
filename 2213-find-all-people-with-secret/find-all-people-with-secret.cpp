bool compare(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}
class Solution {
public:
    int find(int x, vector<int>& p) {
        return p[x] == x ? x : p[x] = find(p[x], p);
    }
    bool join(int a, int b, vector<int>& p, vector<int>& sz) {
        if(find(a, p) == find(b, p)) return false;
        if(sz[find(a, p)] > sz[find(b, p)]) {
            sz[find(a, p)] += sz[find(b, p)];
            p[find(b, p)] = find(a, p);
        } else {
            sz[find(b, p)] += sz[find(a, p)];
            p[find(a, p)] = find(b, p);
        }
        return true;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), compare);
        vector<int> sz(n, 1);
        vector<int> p(n);
        for(int i = 0; i < n; i++) p[i] = i;
        p[firstPerson] = 0;
        for(int i = 0; i < meetings.size();) {
            int time = meetings[i][2];
            vector<int> nodes;
            for(; i < meetings.size() && meetings[i][2] == time; i++) {
                join(meetings[i][0], meetings[i][1], p, sz);
                nodes.push_back(meetings[i][0]);
                nodes.push_back(meetings[i][1]);
            }
            for(int node: nodes) {
                if(find(node, p) != find(0, p)) p[node] = node;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(find(p[i], p) != find(0, p)) continue;
            ans.push_back(i);
        }
        return ans;
    }
};