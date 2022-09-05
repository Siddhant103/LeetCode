/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int s = q.size();
            vector<int> levelOrder;
            while (s--) {
                Node* temp = q.front(); q.pop();
                levelOrder.push_back(temp->val);
                for (auto child: temp->children) {
                    q.push(child);
                }
            }
            result.push_back(levelOrder);
        }
        
        return result;
    }
};