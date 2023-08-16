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
    void getInOrder(TreeNode* root, vector<int>& order) {
        if (root == NULL) {
            return;
        }

        getInOrder(root->left, order);
        order.push_back(root->val);
        getInOrder(root->right, order);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
        if (root == NULL) {
            return order;
        }
        TreeNode* node = root;
        stack<TreeNode*> st;
        while(true) {
            if (node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                if (st.empty()) break;
                node = st.top(); st.pop();
                order.push_back(node->val);
                node = node->right;
            }            
        }

        return order;
    }
};