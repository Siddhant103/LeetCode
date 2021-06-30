/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static bool comp(const pair<int,int>& a, const pair<int,int>& b)
    {
        if(a.second != b.second)
        {
            return a.second < b.second;
        }
        else 
        {
            return a.first < b.first;
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        map<int, vector<pair<int, int>>> m;
        if(root == NULL){
            return result;
        }
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            int n = q.size();
            while(n--){
                pair<TreeNode*, pair<int, int>> temp = q.front(); q.pop();
                m[temp.second.second].push_back({temp.first->val, temp.second.first});
                if(temp.first->left){
                    q.push({temp.first->left ,{temp.second.first + 1, temp.second.second - 1}});
                }
                if(temp.first->right){
                    q.push({temp.first->right ,{temp.second.first + 1, temp.second.second + 1}});
                }
            }
        }
        
        for(auto x: m){
            sort(x.second.begin(), x.second.end(), comp);
            vector<int> ans;
            for(int i=0;i<x.second.size();i++){
                ans.push_back(x.second[i].first);
            }
            result.push_back(ans);
        }
        
        return result;
    }
};