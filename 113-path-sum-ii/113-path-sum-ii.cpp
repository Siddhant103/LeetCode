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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> currPath;
        findPaths(root, currPath, paths, targetSum);
        return paths;
    }
    
    void findPaths(TreeNode* node, vector<int> &currPath, vector<vector<int>> &paths, int sum){
        if (node == NULL) 
            return;
        currPath.push_back(node -> val);
        if (node -> left == NULL && node -> right==NULL && sum == node -> val)
            paths.push_back(currPath);
        findPaths(node -> left, currPath, paths, sum - node -> val);
        findPaths(node -> right, currPath, paths, sum - node -> val);
        currPath.pop_back();
    }
};