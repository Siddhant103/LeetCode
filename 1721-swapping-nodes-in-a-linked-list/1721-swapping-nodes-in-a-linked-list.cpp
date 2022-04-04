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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ListNode* kNode = NULL;
        
        while(--k){
            ptr1 = ptr1->next;
        }
        
        kNode = ptr1;
        ptr1 = ptr1->next;
        
        cout<<kNode->val<<endl;
        
        while(ptr1!=NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        cout<<ptr2->val<<endl;
        int temp = kNode->val;
        kNode->val = ptr2->val;
        ptr2->val = temp;
        
        return head;
    }
};