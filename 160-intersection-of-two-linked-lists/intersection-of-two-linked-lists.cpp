
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        if(headA == headB) {
            return headA;
        }
        ListNode *head1 = headA;
        while(head1 -> next != NULL) {
            head1 = head1 -> next;
        }
        ListNode *head2 = headB;
        while(head2 -> next != NULL) {
            head2 = head2 -> next;
        }
        if(head1 != head2) {
            return NULL;
        }
        head1 -> next = headA;
        ListNode *slow = headB;
        ListNode *fast = headB;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                cout << "YES";
                slow = headB;
                while(slow != fast) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                head1 -> next = NULL;
                return slow;
            }
        }
        head1 -> next = NULL;
        return NULL;
    }
};