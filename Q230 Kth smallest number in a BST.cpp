class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;

        
        while (curr != nullptr || !s.empty()) {
            
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            
            curr = s.top();
            s.pop();

            
            k--;
            if (k == 0) {
                return curr->val; 
            }

            
            curr = curr->right;
        }

        return -1; 
    }
};
