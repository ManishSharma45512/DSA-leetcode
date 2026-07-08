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
    int getDecimalValue(ListNode* head) {
        if (head == nullptr) return 0; // Base Case

        vector<int> num;
        ListNode* temp = head;

        // Gather all binary digits into your vector
        while (temp != nullptr) {
            num.push_back(temp->val);
            temp = temp->next;
        }

        int val = 0;
        int n = num.size();

        
        for (int i = 0; i < n; i++) {
            if (num[i] == 1) {
                val += pow(2, n - 1 - i);
            }
        }

        return val;
    }
};
