class Solution {
    vector<int> parent;
    vector<int> rank;
public:
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    int unionn(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        
        if(root_a == root_b){
            return 0;
        } else{
            if(rank[root_a] > rank[root_b]){
                rank[root_a] += rank[root_b];
                parent[root_b] = root_a;
            } else{
                rank[root_b] += rank[root_a];
                parent[root_a] = root_b;
            }
            return 1;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n < 2)
            return n;
        
        for(int i=0;i<n;++i){
            parent.push_back(i);
            rank.push_back(1);
        }
        
        int components = n;
        for(auto edge: edges){
            components -= unionn(edge[0], edge[1]);
        }
        
        return components;
    }
};