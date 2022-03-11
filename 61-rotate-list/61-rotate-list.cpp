/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next == NULL||k==0) return head;
        
        ListNode* node = head;
        int size =1;
        
        while(node->next != NULL)
        {
            size++;
            node = node->next;
        }
        
        //loop the list
        node->next=head;
        
        //handle the case of k>size
        k = k%size;
        
        //find the node to break the loop at
        while(--size >= k)
        {
            node=node->next;
        }
        
        ListNode* first = node->next;
        node->next=NULL;
        
        return first;
    }
};