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
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        
        queue<Node*> q;
        int depth = 0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                int noOfChildren = (temp->children).size();
                for(int j=0;j<noOfChildren;j++){
                    q.push(temp->children[j]);
                }
            }
            depth++; 
        }
        
        return depth;
    }
};