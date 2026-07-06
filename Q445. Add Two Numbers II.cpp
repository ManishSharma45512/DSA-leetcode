class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Base Cases
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        
        stack<int> s1;
        stack<int> s2;

        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        vector<int> reversedElements;
        
        int carry = 0;

        
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry;
            
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;
            int rem = sum % 10;
            
            
            reversedElements.push_back(rem);
        }

        
        for (int i = reversedElements.size() - 1; i >= 0; i--) {
            current->next = new ListNode(reversedElements[i]);
            current = current->next;
        }

        ListNode* head = dummy->next;
        delete dummy;

        return head;
    }
};
