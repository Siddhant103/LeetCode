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
    vector<int> postorder(Node* root) {
        stack<Node*> s;
        vector<int> ans;
        if(root==NULL)
            return ans;
        
        s.push(root);
        while(!s.empty()){
            Node* topElement = s.top();
            s.pop();
            ans.push_back(topElement->val);
            for(Node* child: topElement->children){
                s.push(child);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};