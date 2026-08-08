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
    void helper(TreeNode* root, int& s, bool isLeft) {
        if (root == nullptr) return;

        //Check if it is a LEFT node AND a LEAF node (no left or right children)
        if (isLeft && root->left == nullptr && root->right == nullptr) {
            s += root->val;
        }

        helper(root->left, s, true);
        helper(root->right, s, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int s = 0;
        helper(root, s, false); // root itself is not a left leaf
        return s;
    }
};
