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
        if(node==nullptr)
            return nullptr;
        
        queue<Node*> q;
        map<Node*, Node*> visited;
        
        Node* new_node = new Node(node->val);
        
        q.push(node);
        visited[node] = new_node;
    
        while(!q.empty()){
            Node* curr_node = q.front();
            cout<<curr_node->val<<endl;
            q.pop();
            Node* new_curr_node = visited[curr_node];
            
            for(int i=0;i<curr_node->neighbors.size();i++){
                if(visited.find(curr_node->neighbors[i]) == visited.end()){
                    Node* new_child = new Node(curr_node->neighbors[i]->val);
                    new_curr_node->neighbors.push_back(new_child);
                    q.push(curr_node->neighbors[i]);
                    visited[curr_node->neighbors[i]] = new_child;
                } else{
                    new_curr_node->neighbors.push_back(visited[curr_node->neighbors[i]]);
                }
            }
        }
        
        return new_node;
    }
};