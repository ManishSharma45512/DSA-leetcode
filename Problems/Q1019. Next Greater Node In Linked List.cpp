class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        if (head == nullptr) {
            vector<int> res;
            return res;
        }

        vector<int> result;
        ListNode* temp = head;

        
        while (temp != nullptr) {
            
            ListNode* tem = temp->next;
            int nextGreater = 0; //Base value

            // Inner loop scans ahead to find the FIRST larger value
            while (tem != nullptr) {
                if (tem->val > temp->val) {
                    nextGreater = tem->val; // Found it!
                    break;                  // Stop immediately to get the NEXT greater, not the maximum
                }
                tem = tem->next; // Move forward normally
            }

            result.push_back(nextGreater);
            temp = temp->next;
        }

        return result;
    }
};
