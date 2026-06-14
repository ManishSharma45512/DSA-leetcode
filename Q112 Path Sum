class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base Case 1: If the tree or branch is empty
        if (root == nullptr) {
            return false;
        }

        // Base Case 2: Check if we are at a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        // Recurse down left and right subtrees with the updated remaining sum
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};
