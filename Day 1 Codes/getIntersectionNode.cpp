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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        int countA = 0, countB = 0;
        while(p1 != NULL) {
            p1 = p1 -> next;
            countA++;
        }
        while(p2 != NULL) {
            p2 = p2 -> next;
            countB++;
        }
        int DIFF = abs(countA - countB);
        if(countA > countB) {
            while(DIFF--) {
                headA = headA -> next;
            }
        } else if(countB > countA) {
            while(DIFF--) {
                headB = headB -> next;
            }
        }
        while(headA != NULL && headB != NULL) {
            if(headA == headB) {
                return headA;
            }
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
};
