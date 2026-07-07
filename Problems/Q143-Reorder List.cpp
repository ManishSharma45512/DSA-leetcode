class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find the middle of the list using slow/fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        // This lets our 'end' pointer walk "backwards" towards the middle
        ListNode* curr = slow->next;
        slow->next = nullptr; // Disconnect the first half from the second half
        ListNode* prev = nullptr;
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // Step 3: Weave the list using your 'start' and 'end' pointers
        ListNode* start = head;  // Starts at the beginning of the 1st half
        ListNode* end = prev;    // Starts at the end of the list (now the head of the 2nd half)
        
        while (start != nullptr && end != nullptr) {
            ListNode* nextStart = start->next; // Save original next node for start
            ListNode* nextEnd = end->next;     // Save original next node for end (which goes "backward")

            // Your weaving logic: Connect start to end, then end to the next start element
            start->next = end;
            end->next = nextStart;

            // Move both pointers forward
            start = nextStart;
            end = nextEnd; // Because it's reversed, this moves it toward the middle!
        }
    }
};
