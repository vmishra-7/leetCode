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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }
        ListNode* tH = head;
        int i = 0, size = 0;
        while(tH != NULL) {
            size++;
            tH = tH -> next;
        }
        if(k % size == 0) {
            return head;
        }
        k %= size;
        tH = head;
        while(i < k) {
            i++;
            tH = tH -> next;
        }
        ListNode* temp = head;
        while(tH -> next != NULL) {
            temp = temp -> next;
            tH = tH -> next;
        }
        ListNode *newHead = temp -> next;
        temp -> next = NULL;
        tH -> next = head;
        return newHead;
    }
};
