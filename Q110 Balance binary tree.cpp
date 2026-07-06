class Solution {
private:
    
    int checkHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0; // An empty tree has a height of 0
        }

        // 1. Check the left subtree
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree is already unbalanced

        // 2. Check the right subtree
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree is already unbalanced

        // 3. Check the current node's balance factor
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Current node is unbalanced
        }

        // 4. If balanced, return the actual height of this node's tree
        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        
        return checkHeight(root) != -1;
    }
};
