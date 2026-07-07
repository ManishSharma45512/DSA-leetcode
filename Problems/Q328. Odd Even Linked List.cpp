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


:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

                                                                          XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head; // Base Case

        int count = 1; 
        ListNode* temp = head;
        vector<int> odd;
        vector<int> even;
        
        
        while (temp != nullptr) {
            if (count % 2 == 0) {
                even.push_back(temp->val);
            } else {
                odd.push_back(temp->val);
            }
            count++;
            temp = temp->next; 
        }

        
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;

        // Append all odd values
        for (int i = 0; i < odd.size(); i++) {
            curr->next = new ListNode(odd[i]);
            curr = curr->next;
        }

        // Append all even values right after
        for (int j = 0; j < even.size(); j++) {
            curr->next = new ListNode(even[j]);
            curr = curr->next;
        }

        ListNode* mainHead = dummyHead->next;
        
        
        delete dummyHead; 

        return mainHead;
    }
};
