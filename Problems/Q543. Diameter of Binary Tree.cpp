/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
    int helper(TreeNode* root, int& maxDiameter) {
        if (root == nullptr) return 0; // Base case

        int leftHeight = helper(root->left, maxDiameter);
        int rightHeight = helper(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return height of current node to its parent
        return 1 + max(leftHeight, rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        helper(root, maxDiameter);
        return maxDiameter;
    }
};
