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
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        cout << q.size();
        while (q.size()) {
            int n = q.size(), sum = 0;
            cout << n << endl;
            if (n == 0) {
                return result;
            }
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            result = sum;
        }
        return result;
    }
};