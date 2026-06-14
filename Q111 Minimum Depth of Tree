class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        // If the left child is missing, look down the right side exclusively
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        
        // If the right child is missing, look down the left side exclusively
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }

        // If both children exist, take the minimum of both paths
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
