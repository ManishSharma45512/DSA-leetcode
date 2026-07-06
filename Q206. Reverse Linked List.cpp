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

                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


class Solution {
public:
    ListNode* reverseList(ListNode* head) {  // TC = O(n) + O(n) = O(2n) => O(n)
        if(head == nullptr) return head;

        vector<int> elements;

        while(head != nullptr) { // O(n)
            elements.push_back(head->val);
            head = head->next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(int i = elements.size() - 1; i >= 0; i--) { // O(n)
            dummy->next = new ListNode(elements[i]);
            dummy = dummy->next;
        }

        ListNode* result = curr->next;
        
        
        delete curr; 

        return result;
    }
};
