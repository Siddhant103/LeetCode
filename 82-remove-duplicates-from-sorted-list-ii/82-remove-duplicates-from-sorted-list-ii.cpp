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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* nextNode = head;
        ListNode* prev = new ListNode(0);
        while(nextNode->next!=NULL){
            if(nextNode->val == nextNode->next->val){
                while(nextNode->next!=NULL && nextNode->val==nextNode->next->val){
                    nextNode->next = nextNode->next->next;
                }
                if(nextNode==head)
                    head = nextNode->next;
                else{
                    ListNode* temp = nextNode;
                    nextNode = prev;
                    prev = temp;
                    nextNode->next = prev->next;
                }
            }
            else{
                prev = nextNode;
                nextNode = nextNode->next;
            }
        }
        
        return head;
    }
};