class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }

       
        int steps = (n / 2) - 1;

        ListNode* track = head;
        while (steps > 0) {
            track = track->next;
            steps--;
        }

        
        ListNode* middleNode = track->next; 
        track->next = middleNode->next;     
        delete middleNode;                  

        return head;
    }
};
