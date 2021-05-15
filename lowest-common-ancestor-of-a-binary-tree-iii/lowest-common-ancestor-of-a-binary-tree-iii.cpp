/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
        if(p==q)
            return p;
        if(p==NULL)
            return q;
        if(q==NULL)
            return p;
        
        Node* left = p->parent;
        Node* right = q->parent;
        
        set<Node*> visited_p;
        visited_p.insert(p);
        
        while(left!=NULL){
            visited_p.insert(left);
            left = left->parent;
        }
        
        if(visited_p.find(q)!=visited_p.end())
            return q;
        
        while(right!=NULL){
            if(visited_p.find(right)!=visited_p.end()){
                return right;
            }
            right = right->parent;
        }
        return NULL;
    }
};