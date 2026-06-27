class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        vector<int> elements;
        ListNode* temp = head;
        
        
        while (temp != nullptr) {
            elements.push_back(temp->val);
            temp = temp->next;
        }

        int n = elements.size();
        
        
        int i = 0;
        int j = n - 1;

        
        while (i < j) {
            
            if (elements[i] != elements[j]) {
                return false; 
            }
            i++; 
            j--;
        }

        return true; 
    }
};
