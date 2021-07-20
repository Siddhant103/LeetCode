/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        
        unordered_map<int, Node*> m;
        return clone(node, m);
    }
    
    Node* clone(Node* node, unordered_map<int, Node*>& m){
        if(m.find(node->val) != m.end()){
            return m[node->val];
        }
        
        Node* copy = new Node(node->val);
        m[node->val] = copy;
        
        for(Node* neighbor: node->neighbors){
            copy->neighbors.push_back(clone(neighbor, m));
        }
        
        return copy;
    }
};