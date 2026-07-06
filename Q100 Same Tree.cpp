class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base Case 1: Both are null, so they are identical
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // Base Case 2: One is null and the other isn't, or values don't match
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }
        
        // Recursive 
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
