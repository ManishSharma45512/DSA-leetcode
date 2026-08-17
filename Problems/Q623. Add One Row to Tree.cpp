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
    void helper(TreeNode* node, int val, int depth, int currentDepth) {
        if (node == nullptr) return;

        // When reaching depth - 1, perform the insertions
        if (currentDepth == depth - 1) {
            TreeNode* oldLeft = node->left;
            TreeNode* oldRight = node->right;

            node->left = new TreeNode(val, oldLeft, nullptr);
            node->right = new TreeNode(val, nullptr, oldRight);
            return;
        }

        // Traverse downwards
        helper(node->left, val, depth, currentDepth + 1);
        helper(node->right, val, depth, currentDepth + 1);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {//empty
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        helper(root, val, depth, 1);
        return root;
    }
};
