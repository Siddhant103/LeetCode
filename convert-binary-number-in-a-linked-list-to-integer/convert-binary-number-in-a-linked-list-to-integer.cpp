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
    ListNode* revLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(head!=NULL){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    int getDecimalValue(ListNode* head) {
        ListNode* reversed = revLL(head);
        int num=0;
        int power=0;
        while(reversed!=NULL){
            num += reversed->val*pow(2,power++);
            reversed = reversed->next;
        }
        return num;
    }
};