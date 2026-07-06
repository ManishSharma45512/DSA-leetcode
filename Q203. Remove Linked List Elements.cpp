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

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

                                                                                       XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* temp = dummyHead;

        
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->val == val) {
                ListNode* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next; 
                delete nodeToDelete;            
                
            } else {
                temp = temp->next; 
            }
        }

        
        ListNode* newHead = dummyHead->next;
        delete dummyHead; 
        
        return newHead;
    }
};
