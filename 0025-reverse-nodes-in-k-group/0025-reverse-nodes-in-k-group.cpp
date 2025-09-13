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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        while (temp) {
            ListNode* kthNode = getKthNode(temp, k);
            if (!kthNode) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            nextNode = kthNode -> next;
            kthNode->next = nullptr;
            ListNode* newHead = reverseList(temp);
            if (temp == head) {
                head = newHead;
            } else {
                prevNode->next = newHead;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;
        while (temp && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }
};