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
    void deleteNode(ListNode* node) {
        // Keep a pointer to the next node so we can safely delete it from memory later
        ListNode* nextNode = node->next;
        
        // 1. Copy the value of the next node into the current node
        node->val = nextNode->val;
        
        // 2. Link the current node to skip over the next node
        node->next = nextNode->next;
        
        // 3. Free the memory of the duplicated next node
        delete nextNode;
    }
};
