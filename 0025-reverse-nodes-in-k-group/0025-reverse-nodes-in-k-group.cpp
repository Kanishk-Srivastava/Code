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
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while (temp && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    void reverseList(ListNode* temp){
        ListNode* prev = nullptr; 
        ListNode* curr = temp; 
        while(curr){
            ListNode* nextNode = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = nextNode; 
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head; 
        ListNode* prevNode = nullptr; 
        ListNode* nextNode = nullptr; 

        while(temp){
            ListNode* kthNode = getKthNode(temp, k); 
            if(kthNode == nullptr){
                if(prevNode) prevNode->next = temp; 
                break; 
            }
            nextNode = kthNode -> next; 
            kthNode -> next = nullptr; 
            reverseList(temp); 
            if(temp == head){
                head = kthNode; 
            } else {
                prevNode->next = kthNode; 
            }
            prevNode = temp; 
            temp = nextNode; 
        }
        return head; 
    }
};