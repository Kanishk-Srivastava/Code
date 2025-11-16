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

struct Compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val; 
    }
}; 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap; 

        for(int i=0; i<lists.size(); i++){
            if(lists[i] != nullptr){
                minHeap.push(lists[i]); //push 1st element of each LL
            }
        }

        ListNode* dummy = new ListNode(-1); //create dummy node to return result; 
        ListNode* tail = dummy; 

        while(!minHeap.empty()){ //pop from heap the smallest el add to LL and push the next el to heap a
            ListNode* topEl = minHeap.top(); 
            minHeap.pop(); 

            tail->next = topEl; 
            tail = tail->next; 

            if(topEl->next){
                minHeap.push(topEl->next); 
            }
        }
    return dummy->next; 
    }
};