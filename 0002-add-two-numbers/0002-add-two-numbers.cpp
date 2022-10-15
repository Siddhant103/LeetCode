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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        ListNode *temp = NULL, *head = NULL;
        int carry = 0, sum;
        while (l1 != NULL || l2 != NULL) {
            sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry) % 10; 
            carry = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry) >= 10 ? 1 : 0;
            ListNode *curr = new ListNode(sum);
            if (!head) {
                head = curr;
            }
            if (temp) {
                temp->next = curr;
            }
            temp = curr;
            l1 = l1 ? l1->next: NULL;
            l2 = l2 ? l2->next: NULL;
        }
        
        if (carry) {
            ListNode *c = new ListNode(carry);
            temp->next = c;
        }
        
        return head;
    }
};