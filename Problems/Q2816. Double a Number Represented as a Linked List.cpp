class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        if(head == nullptr) return head; // Base Case

        //Gather all list values into a string (Your 'sum' step, but overflow-proof!)
        string sumStr = "";
        ListNode* temp = head;
        while(temp != nullptr){
            sumStr += to_string(temp->val);
            temp = temp->next; 
        }

        //Double the giant string number manually
        string doubledStr = "";
        int carry = 0;
        
        
        for (int i = sumStr.length() - 1; i >= 0; i--) {
            int currentDigit = sumStr[i] - '0';
            int product = currentDigit * 2 + carry;
            
            doubledStr += to_string(product % 10);
            carry = product / 10;
        }
        if (carry > 0) {
            doubledStr += to_string(carry);
        }
        
        // Flip it back to forward order since we calculated from right-to-left
        reverse(doubledStr.begin(), doubledStr.end());

        // Move digits into your vecto
        vector<int> num;
        for (char c : doubledStr) {
            num.push_back(c - '0');
        }

        // Rebuild the brand new linked list using your exact loop structure
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        for(int i = 0; i < num.size(); i++){ 
            res->next = new ListNode(num[i]);
            res = res->next;
        }

        ListNode* mainHead = dummy->next;
        delete dummy;
        return mainHead;
    }
};
