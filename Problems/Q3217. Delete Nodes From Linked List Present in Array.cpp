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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (nums.size() == 0 || head == nullptr) return head; // BASE CASE

        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++; 
        }

        ListNode* temp = head;
        ListNode* prev = new ListNode(0); // Dummy node
        ListNode* resultHead = prev;
        prev->next = head; 

        while (temp != nullptr) { 
            if (freq[temp->val] > 0) {
                prev->next = temp->next;
                temp = temp->next;
            } else {
                prev = prev->next;
                temp = temp->next;
            }
        }

        ListNode* mainHead = resultHead->next;
        delete resultHead;

        return mainHead;
    }
};
