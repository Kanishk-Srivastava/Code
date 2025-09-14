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
        unordered_map <Node*, Node*> nodeMap; 
        nodeMap[nullptr] = nullptr; 
        Node* curr = head;
        while(curr){
            Node* newNode = new Node(curr->val); 
            nodeMap[curr] = newNode; 
            curr = curr->next; 
        }

        curr = head; 

        while(curr){
            nodeMap[curr]->next = nodeMap[curr->next]; 
            nodeMap[curr]->random = nodeMap[curr->random]; 
            curr = curr->next; 
        }

        return nodeMap[head]; 
    }
};