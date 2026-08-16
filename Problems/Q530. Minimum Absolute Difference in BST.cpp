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
    void helper(TreeNode* root, TreeNode*& prev, int& mini) {
        if (root == nullptr) return; // Base Case

        helper(root->left, prev, mini);

        if (prev != nullptr) {
            mini = min(mini, root->val - prev->val);
        }
        prev = root;//Update previous node

        helper(root->right, prev, mini);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        TreeNode* prev = nullptr;
        
        helper(root, prev, mini);
        
        return mini;
    }
};
