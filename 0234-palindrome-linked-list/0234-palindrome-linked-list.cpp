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
    ListNode* left; 
    bool isPalindrome(ListNode* head) {
        left = head; 
        return checkRecursively(head); 
    }

    bool checkRecursively(ListNode* right){
        if(!right) return true; 

        if(!checkRecursively(right->next)) return false; 

        if(left->val != right->val) return false; 

        left = left->next; 
        return true; 
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true; 

        ListNode* firstHalfEnd = endOfFirstHalf(head); 

        ListNode* secondHalfStart = reverseList(firstHalfEnd->next); 

        ListNode* p1 = head; 
        ListNode* p2 = secondHalfStart; 

        bool isPalin = true; 

        while(p2){
            if(p1->val != p2->val){
                isPalin = false; 
                break; 
            }
            p1 = p1->next; 
            p2 = p2->next; 
        }

        firstHalfEnd->next = reverseList(secondHalfStart); 
        return isPalin; 
    }


    ListNode* endOfFirstHalf(ListNode* head){
        ListNode* slow = head; 
        ListNode* fast = head; 

        while(fast->next && fast->next->next){
            slow = slow -> next; 
            fast = fast ->next -> next; 
        }

        return slow; 
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr; 

        while(head){
            ListNode* nxt = head->next; 
            head->next = prev; 
            prev = head; 
            head = nxt; 
        }
        return prev; 
    }
};
*/