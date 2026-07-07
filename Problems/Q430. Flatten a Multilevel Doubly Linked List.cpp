/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    void nextLevel(Node* head, vector<int>& traversal) {
        Node* temp = head;
        while (temp != nullptr) {
            
            traversal.push_back(temp->val);

            if (temp->child != nullptr) {
                
                nextLevel(temp->child, traversal);
            }
                
            temp = temp->next;
        }
    }

    Node* flatten(Node* head) {
        if (head == nullptr) return head;

        vector<int> traversal;
        Node* temp = head;

        nextLevel(temp, traversal);

        Node* dummy = new Node(); 
        Node* curr = dummy;

        
        for (int i = 0; i < traversal.size(); i++) {
        
            curr->next = new Node();
            curr->next->val = traversal[i];
            
            temp = curr;
            curr = curr->next;
            curr->prev = temp;
        }

        Node* main = dummy->next;
        
        
        if (main != nullptr) {
            main->prev = nullptr;
        }

        delete dummy; 
        return main;
    }
};
