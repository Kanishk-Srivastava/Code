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
    ListNode* oddEvenList(ListNode* head) {
        // Edge cases: 0, 1, or 2 nodes need no changes
        if (!head || !head->next || !head->next->next) return head;

        // odd will traverse odd-indexed nodes; even for even-indexed nodes.
        // Keep evenHead to reconnect later.
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        // Re-link next pointers to form two lists: odd chain and even chain
        while (even && even->next) {
            odd->next = even->next;        // connect current odd to next odd
            odd = odd->next;                // advance odd

            even->next = odd->next;         // connect current even to next even
            even = even->next;              // advance even
        }

        // Append even list after the odd list
        odd->next = evenHead;
        return head;
    }
};
