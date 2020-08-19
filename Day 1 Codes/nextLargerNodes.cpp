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
    vector<int> nextLargerNodes(ListNode* head) {
        int N = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            N++;
            temp = temp -> next;
        }
        stack<pair<int, int>> S;
        vector<int> output(N, 0);
        int i = 0;
        while(head != NULL) {
            while(!S.empty()) {
                pair<int, int> P = S.top();
                if(P.first >= head -> val) {
                    break;
                }
                output[P.second] = head -> val;
                S.pop();
            }
            S.push({head -> val, i});
            i++;
            head = head -> next;
        }
        return output;
    }
};
