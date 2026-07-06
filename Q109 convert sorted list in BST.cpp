class Solution {
public:
    
    TreeNode* helper(ListNode*& head, int st, int end) {
        if (st > end) return nullptr;
        
        int mid = st + (end - st) / 2;

        // 1. Recursively build the left subtree
        TreeNode* leftChild = helper(head, st, mid - 1);

        // 2. The current head pointer is the mid element. Create the root.
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;

        // 3. Move the head pointer forward to the next element for the right subtree
        head = head->next;

        // 4. Recursively build the right subtree
        root->right = helper(head, mid + 1, end);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int c = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            c++;
        }

        
        return helper(head, 0, c - 1);
    }
};
