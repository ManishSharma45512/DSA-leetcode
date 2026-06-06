class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Edge cases: If either list is already empty, return the other
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        // Initialize head and tail with the smaller first node
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        tail = head;
        
        // Loop while both lists have nodes remaining
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Attach the remaining nodes of the unfinished list
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        return head;
    }
};
