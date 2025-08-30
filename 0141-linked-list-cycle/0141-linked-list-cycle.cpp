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
    bool hasCycle(ListNode *head) {
        // unordered_set<ListNode*> visited; 

        // while(head != NULL){
        //     if(visited.find(head) != visited.end()){
        //         return true;
        //     } else {
        //         visited.insert(head); 
        //         head = head->next; 
        //     }
        // }
        // return false; 
//FLOYD CYCLE DETECTION
        if(!head || !head->next) return false; 

        ListNode* slow = head; 
        ListNode* fast = head; 

        while(fast && fast->next){
            slow = slow->next; 
            fast = fast -> next -> next; 
            if(slow == fast) return true; 
        }
        return false; 
    }
};