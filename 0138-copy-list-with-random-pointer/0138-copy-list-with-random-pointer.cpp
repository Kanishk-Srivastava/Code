/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr; 

        Node* temp = head; 

        while(temp){
            Node* copyNode = new Node(temp->val); 
            copyNode->next = temp->next;
            temp->next = copyNode; 
            temp = temp->next->next; 
        }

        temp = head; 

        while(temp){
            Node* copyNode = temp->next; 
            copyNode->random = temp->random ? temp->random->next : nullptr; 
            temp = temp->next->next; 
        }

        Node* dummyNode = head->next; 
        temp = head; 

        while(temp){
            Node* copyNode = temp->next; 

            temp->next = copyNode->next; 
            if(temp->next){
                copyNode->next = temp->next->next;
            } else copyNode->next = nullptr; 

            temp = temp->next; 
        }

        return dummyNode; 
    }
};