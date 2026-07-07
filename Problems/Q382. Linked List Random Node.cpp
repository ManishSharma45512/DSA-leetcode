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


#include <cstdlib> // For rand()

class Solution {
private:
    // Store the node values for fast O(1) random access
    vector<int> values;

public:
    
    Solution(ListNode* head) {
        ListNode* temp = head;
        
        while (temp != nullptr) {
            values.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    // Returns a random node's value with equal probability
    int getRandom() {
        // Pick a random index between 0 and values.size() - 1 because Module cstdlib give rand() any integer value for if we modulo if with vector size we get range of (0,vector.size()-1)
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
