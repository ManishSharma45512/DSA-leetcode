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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head; // Base Case

        ListNode* lessHead = new ListNode(0);
        ListNode* moreHead = new ListNode(0);

        ListNode* currLess = lessHead;
        ListNode* currMore = moreHead;
        
        ListNode* temp = head;

        // Process the original list into two sublists
        while (temp != nullptr) {
            if (temp->val >= x) {
                currMore->next = temp;
                currMore = currMore->next;
            } else {
                currLess->next = temp;
                currLess = currLess->next;
            }
            temp = temp->next;
        }

        
        currMore->next = nullptr;//to prevent infinite cycle

        currLess->next = moreHead->next;

        ListNode* actualResultHead = lessHead->next;
        
        delete lessHead;
        delete moreHead;

        return actualResultHead;
    }
};
