class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head; 

        while (curr != nullptr) {
            
            ListNode* nextNode = curr->next;

            
            ListNode* prev = dummy;
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }

           
            curr->next = prev->next;
            prev->next = curr;

            
            curr = nextNode;
        }

        ListNode* sortedHead = dummy->next;
        delete dummy; 
        return sortedHead;
    }
};
