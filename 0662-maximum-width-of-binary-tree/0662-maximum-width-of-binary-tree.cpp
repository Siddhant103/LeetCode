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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if (root == NULL) {
            return 0;
        }

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        while (!q.empty()) {
            int s = q.size();
            if (s == 1) {
                q.push({q.front().first,1});
                q.pop();
            }
            if (q.back().second - q.front().second + 1 > ans) {
                ans = q.back().second - q.front().second + 1;
            }
            
            while (s--) {
                auto node = q.front().first;
                auto index = q.front().second;

                if (node->left) {
                    q.push({node->left, 2 * index});
                }
                if (node->right) {
                    q.push({node->right, 2 * index + 1});
                }

                q.pop();
            }
        }

        return ans;
    }
};