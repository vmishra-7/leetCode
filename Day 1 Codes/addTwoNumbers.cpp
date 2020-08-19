/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *head = NULL;
        ListNode* tail = NULL;
        while(l1 != NULL && l2 != NULL) {
            sum += (l1 -> val + l2 -> val);
            if(head == NULL) {
                head = new ListNode(sum % 10);
                tail = head;
            } else {
                tail -> next = new ListNode(sum % 10);
                tail = tail -> next;
            }
            sum = (sum / 10);
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != NULL) {
            sum += l1 -> val;
            tail -> next = new ListNode(sum % 10);
            tail = tail -> next;
            sum /= 10;
            l1 = l1 -> next;
        }
        while(l2 != NULL) {
            sum += l2 -> val;
            tail -> next = new ListNode(sum % 10);
            tail = tail -> next;
            sum /= 10;
            l2 = l2 -> next;
        }
        if(sum != 0) {
            ListNode* newNode = new ListNode(sum);
            tail -> next = newNode;
        }
        return head;
    }
};
