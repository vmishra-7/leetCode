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
        if(head == NULL) {
            return NULL;
        }
        ListNode* prev = head;
        ListNode* temp = prev -> next;
        while(temp != NULL) {
            if(prev -> val == temp -> val) {
                prev -> next = temp -> next;
                temp = temp -> next;
                continue;
            }
            prev = temp;
            temp = temp -> next;
        }
        return head;
    }
};
